namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum BindType : int
    {
        None = 0,
        BindOnPickup = 1, // 拾取绑定
        BindOnEquip = 2,  // 装备绑定
        AccountBound = 3  // 账号绑定
    }
}
