namespace Rathalos.Core.Protocol.Data.NewPlayerInit
{
    public class InitItem
    {
        public int Id { get; set; }

        public int ItemId { get; set; }

        public int Count { get; set; }

        public int AutoEquip { get; set; }

        public int AutoStore { get; set; }
    }
}
