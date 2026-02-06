using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Tqqapi.Classes;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.Cryptography;
using Rathalos.Core.Utils.IO;
using System.Net;
using System.Net.Sockets;

namespace Rathalos.Servers.Base.Core.Network
{
    public abstract class BaseClient
    {
        protected delegate void DataReceivedHandler(byte[] data);

        private readonly ushort _maxBufferSize = 2048;
        private readonly Socket _socket;
        private readonly ChannelBuffer _buffer;
        private string _ipAddress;
        private readonly object _sendLock = new object();
        private bool _isReceiving = false;
        private readonly object _receiveLock = new object();
        private bool _isDisconnected = false;
        private readonly object _disconnectLock = new object();
        protected readonly ILogger _logger;
        protected readonly CancellationTokenSource _tokenSource;
        protected TpduCryptoAes128 _crypto = null;

        protected BaseClient(Socket socket, ILogger logger)
        {
            _socket = socket;
            _logger = logger;
            _tokenSource = new CancellationTokenSource();
            _ipAddress = (_socket.RemoteEndPoint as IPEndPoint)?.ToString() ?? "0.0.0.0";
            _buffer = new ChannelBuffer(capacity: _maxBufferSize); // Higher capacity for better performance
        }

        public string IPAddress => _ipAddress;
        public bool IsConnected => _socket.Connected && !_isDisconnected && !_tokenSource.IsCancellationRequested;
        public TpduCryptoAes128 Crypto => _crypto;

        public async Task Receive()
        {
            // Prevent multiple concurrent receive operations
            lock (_receiveLock)
            {
                if (_isReceiving)
                    return;
                _isReceiving = true;
            }

            try
            {
                // Start the message processing task
                var processingTask = Task.Run(ProcessMessagesAsync, _tokenSource.Token);

                // Main receive loop
                while (!_tokenSource.IsCancellationRequested && _socket.Connected && !_isDisconnected)
                {
                    byte[] buffer = new byte[_maxBufferSize];

                    int receivedBytes = await _socket.ReceiveAsync(buffer, _tokenSource.Token);
                    if (receivedBytes <= 0 || _tokenSource.IsCancellationRequested)
                    {
                        _buffer.CompleteWriter();
                        await Disconnect();
                        break;
                    }

                    // Write to channel buffer asynchronously
                    await _buffer.WriteAsync(buffer, 0, receivedBytes, _tokenSource.Token);
                }

                // Wait for message processing to complete
                await processingTask;
            }
            catch (Exception ex)
            {
                if (!_tokenSource.IsCancellationRequested && !_isDisconnected)
                {
                    _logger.LogError("Error in receive loop for client {Client}: {Error}", this, ex);
                    await Disconnect();
                }
            }
            finally
            {
                lock (_receiveLock)
                {
                    _isReceiving = false;
                }
            }
        }

        private async Task ProcessMessagesAsync()
        {
            var accumulatedBuffer = new List<byte>();

            try
            {
                while (!_tokenSource.IsCancellationRequested && !_isDisconnected)
                {
                    // Read all available data from the channel
                    var newData = await _buffer.ReadAllAvailableAsync(_tokenSource.Token);

                    if (newData.Length == 0)
                    {
                        // No new data, wait a bit before checking again
                        await Task.Delay(10, _tokenSource.Token);
                        continue;
                    }

                    // Add new data to accumulated buffer
                    accumulatedBuffer.AddRange(newData);

                    // Try to process complete messages
                    var bufferArray = accumulatedBuffer.ToArray();
                    FastBigEndianReader reader = new(bufferArray)
                    {
                        Position = 0,
                        MaxPosition = bufferArray.Length
                    };

                    var initialPosition = reader.Position;
                    await OnDataReceived(reader);

                    // Remove processed data from accumulated buffer
                    var processedBytes = (int)(reader.Position - initialPosition);
                    if (processedBytes > 0)
                    {
                        accumulatedBuffer.RemoveRange(0, processedBytes);
                    }
                }
            }
            catch (OperationCanceledException)
            {
                // Expected when cancellation is requested
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Disconnect due to an error in message processing for client {Client} : {Error}", this, ex);
                await this.Disconnect();
            }
        }

        public void Send(TPDUExt headerExtension)
        {
            Send(new Message(headerExtension));
            _logger.LogInformation("{SendPacket} [TPDU] ({Client}) {PacketType}", ConsoleFormat.SendPacket, this, headerExtension.GetType().Name);
        }

        public void Send(CSPkgBody body)
        {
            Send(new Message(body));
            _logger.LogInformation("{SendPacket} [GAME] ({Client}) {PacketType}", ConsoleFormat.SendPacket, this, body.GetType().Name);
        }

        private void Send(Message message)
        {
            lock (_sendLock)
            {
                message.SetEncryptionMethod(_crypto);
                BigEndianWriter writer = new();
                message.Pack(writer);


                _ = SendAsync(writer.Data);
            }

        }

        private async Task SendAsync(byte[] data)
        {
            if (_tokenSource.IsCancellationRequested || !_socket.Connected || _isDisconnected)
                return;

            try
            {
                await _socket.SendAsync(data, _tokenSource.Token);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error sending data to client {Client}", this);
                await Disconnect();
            }
        }

        public async Task Disconnect()
        {
            Send(new TpduCloseConnection());

            // Prevent multiple simultaneous disconnect operations
            lock (_disconnectLock)
            {
                if (_isDisconnected)
                    return;
                _isDisconnected = true;
            }

            try
            {

                _logger.LogDebug("Starting disconnect process for client {Client}", this);

                // Notify about disconnection before cleanup
                OnDisconnected();

                // Cancel all operations to stop receive loops and other tasks
                _tokenSource.Cancel();

                // Complete the buffer writer to signal no more data will be written
                _buffer.CompleteWriter();

                // Gracefully shutdown the socket if still connected
                await ShutdownSocket();

                // Dispose resources
                _buffer.Dispose();

                _logger.LogDebug("Disconnect process completed for client {Client}", this);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error during disconnect for client {Client}", this);
            }
        }

        private async Task ShutdownSocket()
        {
            if (_socket == null)
                return;

            try
            {
                // Check if socket is still connected before attempting shutdown
                if (_socket.Connected)
                {
                    // Shutdown socket communication gracefully
                    // SocketShutdown.Both closes both send and receive operations
                    _socket.Shutdown(SocketShutdown.Both);

                    // Give a brief moment for the shutdown to complete
                    await Task.Delay(100);
                }
            }
            catch (SocketException ex) when (ex.SocketErrorCode == SocketError.NotConnected)
            {
                // Socket was already disconnected, this is fine
                _logger.LogDebug("Socket was already disconnected during shutdown for client {Client}", this);
            }
            catch (ObjectDisposedException)
            {
                // Socket was already disposed, this is fine
                _logger.LogDebug("Socket was already disposed during shutdown for client {Client}", this);
            }
            catch (Exception ex)
            {
                _logger.LogWarning(ex, "Error during socket shutdown for client {Client}", this);
            }
            finally
            {
                try
                {
                    // Always try to close the socket
                    _socket.Close();
                }
                catch (Exception ex)
                {
                    _logger.LogWarning(ex, "Error closing socket for client {Client}", this);
                }
            }
        }

        // Alternative disconnect method with timeout for forced disconnection
        public async Task DisconnectWithTimeout(TimeSpan timeout = default)
        {
            if (timeout == default)
                timeout = TimeSpan.FromSeconds(5);

            using var timeoutCts = new CancellationTokenSource(timeout);

            try
            {
                // Try graceful disconnect first
                var disconnectTask = Disconnect();
                await disconnectTask.WaitAsync(timeoutCts.Token);
            }
            catch (OperationCanceledException)
            {
                _logger.LogWarning("Graceful disconnect timed out for client {Client}, forcing closure", this);
                await ForceDisconnect();
            }
        }

        private async Task ForceDisconnect()
        {
            try
            {
                Send(new TpduCloseConnection());
                _tokenSource.Cancel();
                _buffer?.CompleteWriter();

                // Force close the socket without graceful shutdown
                _socket?.Close();

                _buffer?.Dispose();
            }
            catch (Exception ex)
            {
                _logger.LogError(ex, "Error during forced disconnect for client {Client}", this);
            }
        }

        protected abstract Task OnDataReceived(IDataReader reader);

        public virtual void OnConnected()
        {
            _logger.LogInformation($"[{this}] client is connected !");
        }

        public virtual void OnDisconnected()
        {
            _logger.LogInformation($"[{this}] client is disconnected !");
        }

        public override string ToString()
        {
            return IPAddress;
        }
    }
}
