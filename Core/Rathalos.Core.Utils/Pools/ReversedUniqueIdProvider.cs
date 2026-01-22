namespace Rathalos.Core.Utils.Pools
{
	public class ReversedUniqueIdProvider : UniqueIdProvider
	{
		public ReversedUniqueIdProvider()
		{
		}

		public new static ReversedUniqueIdProvider Default
		{
			get
			{
				return new ReversedUniqueIdProvider(-1);
			}
		}

		public ReversedUniqueIdProvider(long lastId)
			: base(lastId)
		{
		}

		public ReversedUniqueIdProvider(IEnumerable<long> freeIds)
			: base(freeIds)
		{
		}

		protected override long Next()
		{
			return Interlocked.Decrement(ref m_highestId);
		}

		public override long Peek()
		{
			long id;

			if (!m_freeIds.IsEmpty)
			{
				if (!m_freeIds.TryPeek(out id))
				{
					// if we can't dequeue, we return the next id
					return m_highestId - 1;
				}
			}
			else
				return m_highestId - 1;

			return id;
		}

		public override void SetMaxId(long id)
		{
			if (id < m_highestId)
				m_highestId = id;
		}
	}
}
