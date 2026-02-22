using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum LevelWeatherEnum
    {
        Sunny = 1,
        SmallRain = 2,
        HeavyRain = 4,
	    Snow = 8,
    	Blizzard = 16,
    	Foggy = 32,
    	Cloudy = 64,
    	AfterRain = 128,
    	SandStorm = 256
    }
}
