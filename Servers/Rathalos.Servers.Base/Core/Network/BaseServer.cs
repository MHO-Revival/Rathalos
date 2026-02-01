using Microsoft.Extensions.Hosting;
using Microsoft.Extensions.Logging;
using Rathalos.Servers.Base.Core.Configurations;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.Base.Services.Threads;
using System.Net;
using System.Net.Sockets;

namespace Rathalos.Servers.Base.Core.Network
{
	public abstract class BaseServer<TClient, TConfiguration> : BackgroundService
		where TClient : BaseClient
		where TConfiguration : BaseServerConfiguration, new()
	{
		private readonly int _maxConcurrentialConnections = 1000;
		private readonly SemaphoreSlim _connectionSemaphore;
		protected Socket _socket;
		protected readonly ILogger _logger;
		protected readonly TaskPool _taskPool;
		protected CancellationTokenSource _tokenSource;
		protected DateTime _timeToShutdown;
		protected static readonly NetworkService<TClient> _clients = new NetworkService<TClient>();

		public BaseServer(ILogger<TClient> logger)
		{
			_logger = logger;
			_taskPool = new TaskPool("Server TaskPool");
			_connectionSemaphore = new SemaphoreSlim(_maxConcurrentialConnections, _maxConcurrentialConnections);
			Instance = this;
		}

		public static IEnumerable<ISaveService> SaveableServices { get; set; } = new List<ISaveService>();
		public static NetworkService<TClient> NetworkService => _clients;
		public static TConfiguration Configuration { get; set; }
		public static BaseServer<TClient, TConfiguration> Instance { get; set; }
		public bool IsStarted { get; protected set; }
		protected abstract TClient CreateClient(Socket clientSocket);

		protected override Task ExecuteAsync(CancellationToken stoppingToken)
		{
			_tokenSource = CancellationTokenSource.CreateLinkedTokenSource(stoppingToken);
			_ = Run();

			return Task.CompletedTask;
		}

		protected virtual async Task Run()
		{
			await Task.Run(() => Start(Configuration.AddressIP, Configuration.Port), _tokenSource.Token);

			while (!_tokenSource.IsCancellationRequested)
			{
				string cmd = Console.ReadLine();
			}
		}

		public void Start(string ip, int port)
		{
			try
			{
				_socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
				_socket.Bind(new IPEndPoint(IPAddress.Parse(ip), port));
				_socket.Listen(_maxConcurrentialConnections);
                _taskPool.Start(_tokenSource);
				_taskPool.SchedulePeriodically(Configuration.SaveInterval.TotalSeconds, Save);
				OnServerStarted();

				_ = Accept();
			}
			catch (Exception ex)
			{
				_logger.LogError(ex, "Error occurred on socket start for server");
			}
		}

		public async Task Accept()
		{
			while (_socket != null && !_tokenSource.IsCancellationRequested)
			{
				try
				{
					// Wait for available connection slot
					await _connectionSemaphore.WaitAsync(_tokenSource.Token);

					// Check if we're still accepting connections
					if (_tokenSource.IsCancellationRequested)
					{
						_connectionSemaphore.Release();
						break;
					}

					// Accept the client connection
					var clientSocket = await _socket.AcceptAsync().ConfigureAwait(false);

					// Handle the client connection asynchronously without blocking Accept loop
					_ = Task.Run(async () => await HandleClientConnection(clientSocket), _tokenSource.Token);
				}
				catch (ObjectDisposedException)
				{
					// Socket was disposed, exit gracefully
					_logger.LogInformation("Accept loop terminated: Socket disposed");
					break;
				}
				catch (OperationCanceledException)
				{
					// Cancellation requested, exit gracefully
					_logger.LogInformation("Accept loop terminated: Cancellation requested");
					break;
				}
				catch (SocketException ex) when (ex.SocketErrorCode == SocketError.Interrupted)
				{
					// Socket operation was interrupted, likely due to shutdown
					_logger.LogInformation("Accept loop terminated: Socket interrupted");
					break;
				}
				catch (SocketException ex)
				{
					_logger.LogError(ex, "Socket error occurred while accepting connections");
					
					// For critical socket errors, break the loop
					if (ex.SocketErrorCode == SocketError.NotSocket || 
						ex.SocketErrorCode == SocketError.InvalidArgument)
					{
						break;
					}
					
					// For other errors, wait a bit before retrying
					await Task.Delay(1000, _tokenSource.Token);
				}
				catch (Exception ex)
				{
					_logger.LogError(ex, "Unexpected error occurred while accepting connections");
					
					// Wait before retrying to prevent tight error loops
					await Task.Delay(1000, _tokenSource.Token);
				}
			}

			_logger.LogInformation("Accept loop has terminated");
		}

		private async Task HandleClientConnection(Socket clientSocket)
		{
			TClient client = null;
			try
			{
				// Validate the client socket
				if (clientSocket == null || !clientSocket.Connected)
				{
					_logger.LogWarning("Received invalid or disconnected client socket");
					return;
				}

				// Create and configure the client
				client = CreateClient(clientSocket);
				if (client == null)
				{
					_logger.LogError("Failed to create client instance");
					clientSocket.Close();
					return;
				}

				// Add client to network service
				NetworkService.AddClient(client);
				
				// Notify that client connected
				client.OnConnected();

				// Start receiving data from the client
				await client.Receive();
			}
			catch (Exception ex)
			{
				_logger.LogError(ex, "Error handling client connection from {RemoteEndpoint}", 
					clientSocket?.RemoteEndPoint?.ToString() ?? "unknown");
				
				// Clean up the client if it was created
				if (client != null)
				{
					try
					{
						NetworkService.RemoveClient(client);
						await client.Disconnect();
					}
					catch (Exception cleanupEx)
					{
						_logger.LogError(cleanupEx, "Error during client cleanup");
					}
				}
				else
				{
					// If client wasn't created, close the socket directly
					try
					{
						clientSocket?.Close();
					}
					catch (Exception socketEx)
					{
						_logger.LogError(socketEx, "Error closing client socket during cleanup");
					}
				}
			}
			finally
			{
				// Always release the connection semaphore
				_connectionSemaphore.Release();
			}
		}

		protected abstract void OnServerStarted();

		public void Shutdown(TimeSpan delayBeforeShutdown)
		{
			_timeToShutdown = DateTime.Now.Add(delayBeforeShutdown);
			_taskPool.SchedulePeriodically(60, CheckShutdown);
		}

		protected virtual void CheckShutdown()
		{
			if (_timeToShutdown < DateTime.Now)
			{
				OnShutdown();
			}
		}

		protected virtual void OnShutdown()
		{
			_taskPool.Stop();
			_tokenSource.Cancel();

			// Close the listening socket to stop accepting new connections
			try
			{
				_socket?.Close();
			}
			catch (Exception ex)
			{
				_logger.LogError(ex, "Error closing server socket during shutdown");
			}

			// Disconnect all clients
			NetworkService.ForEach(client => {
				var task = client.Disconnect();
				Task.WaitAny(task);
			});

			// Dispose the connection semaphore
			_connectionSemaphore?.Dispose();

			Save();
		}

		public virtual void Save()
		{
			foreach (var saveService in SaveableServices)
			{
				saveService.Save();
			}
		}
	}
}
