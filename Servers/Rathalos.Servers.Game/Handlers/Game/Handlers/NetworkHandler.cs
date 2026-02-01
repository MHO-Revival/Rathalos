using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World.Handlers.Game.Handlers
{
    public sealed class NetworkHandler : IMessageHandler
    {
        [GamePacketHandler<CSMultiNetIpinfo>]
        public Task HandleMultiNetIpInfo(WorldClient client, CSMultiNetIpinfo message)
        {
            // Handle multi-network IP info here
            // This is maybe for switching servers or optimizing network routes with a tpdu server as front door.
            Console.WriteLine($"Received MultiNet IP Info from Client {client.SyncGuid}: {message.SelectIP}, Domain: {message.DomainName}");
            Thread.Sleep(5000);
            client.Send(new CSMultiIspSequenceNtf
            {
                Sequence = 1
            });
            return Task.CompletedTask;
        }

        [GamePacketHandler<CSCheckVersionReq>]
        public Task HandleCheckVersionRequest(WorldClient client, CSCheckVersionReq message)
        {
            // Handle version check request here
            Console.WriteLine($"Client {client.SyncGuid} is checking version: {message.MajorVerNo}.{message.MinorVerNo}.{message.RevisVerNo}.{message.BuildVerNo} (ProtoVer: {message.ProtoVer}, IgnoreTag: {message.IgnoreTag}, Feature:hash:{message.Feature.FeatureHash})");
            client.Send(new CSCheckVersionRsp
            {
                BuildVerNo = message.BuildVerNo,
                MajorVerNo = message.MajorVerNo,
                MinorVerNo = message.MinorVerNo,
                RevisVerNo = message.RevisVerNo,
                Feature = message.Feature,
                ErrNo = 0, // Indicate success
            });
            return Task.CompletedTask;
        }

        [GamePacketHandler<C2SFileCheckReq>]
        public Task HandleFileCheckRequest(WorldClient client, C2SFileCheckReq message)
        {
            // Handle file check request here
            Console.WriteLine($"Client {client.SyncGuid} is requesting file check - Code: {message.Code}, ScanFinish: {message.ScanFinish}, ScanTime: {message.ScanTime}, TimeoutReScan: {message.TimeoutReScan}");
            client.Send(new S2CFileCheckRsp
            {
                Code = 0,
            });
            Thread.Sleep(1000);
            client.Send(new CSMultiIspSequenceNtf
            {
                Sequence = 1
            });
            return Task.CompletedTask;
        }

        [GamePacketHandler<CSPkgTimerRecord>]
        public Task HandlePkgTimerRecord(WorldClient client, CSPkgTimerRecord message)
        {
            
            return Task.CompletedTask;
        }
    }
}
