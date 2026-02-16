using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Game.Actors;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Servers.World.Services;
using System.Threading.Channels;

namespace Rathalos.Servers.World.Handlers.Game.Handlers
{
    public sealed class NetworkHandler : IMessageHandler
    {
        [GamePacketHandler<CSMultiNetIpinfo>]
        public Task HandleMultiNetIpInfo(WorldClient client, CSMultiNetIpinfo message)
        {
            SendInitConnectionPacket(client);
            // Handle multi-network IP info here
            // This is maybe for switching servers or optimizing network routes with a tpdu server as front door.
            Console.WriteLine($"Received MultiNet IP Info from Client {client.SyncGuid}: {message.SelectIP}, Domain: {message.DomainName}");
            client.Send(new CSMultiIspSequenceNtf
            {
                Sequence = int.MaxValue //IDK if it's 0 it makes open the channel panel, maybe it's the channel line id ???
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

            client.Send(new CSShakeHand
            {
                VerifyCode = 1
            });

            return Task.CompletedTask;
        }

        [GamePacketHandler<CSShakeHand>]
        public async Task HandleShakeHand(WorldClient client, CSShakeHand message)
        {
            // Handle shake hand here
            Console.WriteLine($"Client {client.SyncGuid} sent shake hand with VerifyCode: {message.VerifyCode}");

            var records = await RathalosDbService.Instance.Query<CharacterRecord>(x => x.AccountId == client.Account.Id).ToListAsync();
            client.Characters = [.. records.Select(x => new Character(client, x))];
            CharacterHandler.SendCharacterListResponse(client);
        }

        [GamePacketHandler<CSLineInfoReq>]
        public Task HandleLineInfoRequest(WorldClient client, CSLineInfoReq message)
        {
            Console.WriteLine($"Client {client.SyncGuid} requesting line info");

            // Respond with available server lines/channels
            client.Send(new CSLineInfoRsp
            {
                LineInfo =
                [
                    new LineInfo
                    {
                        LineID = 1,
                        State = 2  // 2 = Normal (available)
                    }
                ]
            });

            return Task.CompletedTask;
        }

        [GamePacketHandler<CSSelectLineReq>]
        public Task HandleSelectLineRequest(WorldClient client, CSSelectLineReq message)
        {
            Console.WriteLine($"Client {client.SyncGuid} selected line: {message.LineID}");

            // Client selected a line, now they can proceed to request roles
            // No response packet needed - client will automatically send LIST_ROLE_REQ next

            return Task.CompletedTask;
        }

        [GamePacketHandler<CSPkgTimerRecord>(LogPacket = false)]
        public Task HandlePkgTimerRecord(WorldClient client, CSPkgTimerRecord message)
        {

            return Task.CompletedTask;
        }

        [GamePacketHandler<CSPkgTransAntiData>(LogPacket = false)]
        public Task HandlePkgTransAntiData(WorldClient client, CSPkgTransAntiData message)
        {
            // IDK what this packet is for, it seems to be some kind of anti-cheat or anti-tamper data sent by the client 
            // or maybe it's only for limiting players to play too much, since it has a timer record packet that maybe is for tracking play time
            return Task.CompletedTask;
        }

        private static void SendInitConnectionPacket(WorldClient client)
        {
            client.Send(new CSWaitQueueInfo
            {
                IsVIP = 0,
                NormalWaitTime = 0,
                Position = 0,
                VIPWaitTime = 0
            });

            client.Send(new CSServerSyncInfoAck
            {
                SyncTime = DateTime.UtcNow.GetUnixTimeStampLong()
            });

            client.Send(new CSSvrStatusNtf
            {
                OnlinePlayerNum = 1,
                PlayerInTown = 0,
                PlayerInBattle = 0,
                ActiveInstanceCount = 1,
                PlayerInWaitQueue = 0,
                WorldFPS = 60.0f,
                TownFPS = [.. Enumerable.Repeat(60.0f, 10)],
                BattleFPS = [.. Enumerable.Repeat(60.0f, 10)]
            });

            //client.Send(new CSLineInfoRsp
            //{
            //    LineInfo = [
            //        new LineInfo
            //        {
            //            LineID = 1,
            //            State = (ushort)ChannelStateEnum.Idle,
            //        },
            //        new LineInfo
            //        {
            //            LineID = 2,
            //            State = (ushort)ChannelStateEnum.Idle,
            //        },
            //    ]
            //});
            //client.Send(new CSNewLineInfo
            //{
            //    LineID = 1
            //});
        }

    }
}
