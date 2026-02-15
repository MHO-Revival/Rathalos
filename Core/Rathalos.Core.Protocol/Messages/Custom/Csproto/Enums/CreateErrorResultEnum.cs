using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum CreateErrorResultEnum
    {
        OK = 0,
        MaxCharacterReached = 1,
        NameContainsIllegalCharacters = 3,
        NameAlreadyTaken = 4,
        UnderclothesInvalid = 5,
        HairInvalid = 6,
        TattooInvalid = 7,
        FaceInvalid = 8,

    }
}
