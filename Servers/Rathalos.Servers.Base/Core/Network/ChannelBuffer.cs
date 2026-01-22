using System.Threading.Channels;

namespace Rathalos.Servers.Base.Core.Network
{
    /// <summary>
    /// High-performance buffer using channels for concurrent access
    /// </summary>
    public class ChannelBuffer : IDisposable
    {
        private readonly Channel<byte[]> _dataChannel;
        private readonly ChannelWriter<byte[]> _writer;
        private readonly ChannelReader<byte[]> _reader;
        private readonly object _combinedBufferLock = new();
        private bool _disposed;
        private bool _writerCompleted;

        public ChannelBuffer(int capacity = 100)
        {
            var options = new BoundedChannelOptions(capacity)
            {
                FullMode = BoundedChannelFullMode.Wait,
                SingleReader = true,
                SingleWriter = false,
                AllowSynchronousContinuations = false
            };

            _dataChannel = Channel.CreateBounded<byte[]>(options);
            _writer = _dataChannel.Writer;
            _reader = _dataChannel.Reader;
        }

        public async Task WriteAsync(byte[] data, int offset, int count, CancellationToken cancellationToken = default)
        {
            if (_disposed || _writerCompleted) 
                return;

            try
            {
                var chunk = new byte[count];
                Array.Copy(data, offset, chunk, 0, count);
                await _writer.WriteAsync(chunk, cancellationToken);
            }
            catch (InvalidOperationException)
            {
                // Writer was completed, ignore
            }
            catch (OperationCanceledException)
            {
                // Operation was cancelled, ignore
            }
        }

        public async Task<byte[]> ReadAllAvailableAsync(CancellationToken cancellationToken = default)
        {
            if (_disposed) 
                return Array.Empty<byte>();

            // First, read all immediately available data
            var immediateData = new List<byte>();
            lock (_combinedBufferLock)
            {
                while (_reader.TryRead(out var chunk))
                {
                    immediateData.AddRange(chunk);
                }
            }

            // If no immediate data and writer isn't completed, try to wait for some
            if (immediateData.Count == 0 && !_writerCompleted)
            {
                try
                {
                    // Use a very short timeout to avoid blocking too long
                    using var timeoutCts = CancellationTokenSource.CreateLinkedTokenSource(cancellationToken);
                    timeoutCts.CancelAfter(TimeSpan.FromMilliseconds(50));
                    
                    if (await _reader.WaitToReadAsync(timeoutCts.Token))
                    {
                        lock (_combinedBufferLock)
                        {
                            while (_reader.TryRead(out var chunk))
                            {
                                immediateData.AddRange(chunk);
                            }
                        }
                    }
                }
                catch (OperationCanceledException)
                {
                    // Timeout or cancellation, return what we have
                }
            }

            return immediateData.ToArray();
        }

        public void CompleteWriter()
        {
            if (!_writerCompleted)
            {
                _writerCompleted = true;
                _writer.Complete();
            }
        }

        public bool IsCompleted => _writerCompleted && !_reader.TryPeek(out _);

        public void Dispose()
        {
            if (!_disposed)
            {
                CompleteWriter();
                _disposed = true;
            }
        }
    }
}