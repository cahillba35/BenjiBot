#pragma once


// --------------------------------------------------------
struct IsAttackable 
{
	bool operator()(const sc2::Unit& unit) 
	{
		switch (unit.unit_type.ToType()) 
		{
			// These are examples, we need to check more things.
			case sc2::UNIT_TYPEID::ZERG_OVERLORD:    return false;
			case sc2::UNIT_TYPEID::ZERG_OVERSEER:    return false;
			case sc2::UNIT_TYPEID::PROTOSS_OBSERVER: return false;

			default: return true;
		}
	}
};

// --------------------------------------------------------
struct IsBuilding 
{
	bool operator()(const sc2::Unit& unit)
	{
		switch (unit.unit_type.ToType())
		{
			case sc2::UNIT_TYPEID::TERRAN_ARMORY:               return true;
			case sc2::UNIT_TYPEID::PROTOSS_ASSIMILATOR:         return true;
			case sc2::UNIT_TYPEID::ZERG_BANELINGNEST:           return true;
			case sc2::UNIT_TYPEID::TERRAN_BARRACKS:             return true;
			case sc2::UNIT_TYPEID::TERRAN_BARRACKSREACTOR:      return true;
			case sc2::UNIT_TYPEID::TERRAN_BARRACKSTECHLAB:      return true;
			case sc2::UNIT_TYPEID::TERRAN_BUNKER:               return true;
			case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER:        return true;
			case sc2::UNIT_TYPEID::PROTOSS_CYBERNETICSCORE:     return true;
			case sc2::UNIT_TYPEID::PROTOSS_DARKSHRINE:          return true;
			case sc2::UNIT_TYPEID::TERRAN_ENGINEERINGBAY:       return true;
			case sc2::UNIT_TYPEID::ZERG_EVOLUTIONCHAMBER:       return true;
			case sc2::UNIT_TYPEID::ZERG_EXTRACTOR:              return true;
			case sc2::UNIT_TYPEID::TERRAN_FACTORY:              return true;
			case sc2::UNIT_TYPEID::TERRAN_FACTORYREACTOR:       return true;
			case sc2::UNIT_TYPEID::TERRAN_FACTORYTECHLAB:       return true;
			case sc2::UNIT_TYPEID::PROTOSS_FLEETBEACON:         return true;
			case sc2::UNIT_TYPEID::PROTOSS_FORGE:               return true;
			case sc2::UNIT_TYPEID::TERRAN_FUSIONCORE:           return true;
			case sc2::UNIT_TYPEID::PROTOSS_GATEWAY:             return true;
			case sc2::UNIT_TYPEID::PROTOSS_WARPGATE:            return true;
			case sc2::UNIT_TYPEID::TERRAN_GHOSTACADEMY:         return true;
			case sc2::UNIT_TYPEID::ZERG_HATCHERY:               return true;
			case sc2::UNIT_TYPEID::ZERG_HYDRALISKDEN:           return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTATIONPIT:         return true;
			case sc2::UNIT_TYPEID::TERRAN_MISSILETURRET:        return true;
			case sc2::UNIT_TYPEID::PROTOSS_NEXUS:               return true;
			case sc2::UNIT_TYPEID::ZERG_NYDUSCANAL:             return true;
			case sc2::UNIT_TYPEID::ZERG_NYDUSNETWORK:           return true;
			case sc2::UNIT_TYPEID::PROTOSS_PHOTONCANNON:        return true;
			case sc2::UNIT_TYPEID::PROTOSS_PYLON:               return true;
			case sc2::UNIT_TYPEID::TERRAN_REFINERY:             return true;
			case sc2::UNIT_TYPEID::ZERG_ROACHWARREN:            return true;
			case sc2::UNIT_TYPEID::PROTOSS_ROBOTICSBAY:         return true;
			case sc2::UNIT_TYPEID::PROTOSS_ROBOTICSFACILITY:    return true;
			case sc2::UNIT_TYPEID::TERRAN_SENSORTOWER:          return true;
			case sc2::UNIT_TYPEID::ZERG_SPAWNINGPOOL:           return true;
			case sc2::UNIT_TYPEID::ZERG_SPINECRAWLER:           return true;
			case sc2::UNIT_TYPEID::ZERG_SPIRE:                  return true;
			case sc2::UNIT_TYPEID::ZERG_SPORECRAWLER:           return true;
			case sc2::UNIT_TYPEID::PROTOSS_STARGATE:            return true;
			case sc2::UNIT_TYPEID::TERRAN_STARPORT:             return true;
			case sc2::UNIT_TYPEID::TERRAN_STARPORTREACTOR:      return true;
			case sc2::UNIT_TYPEID::TERRAN_STARPORTTECHLAB:      return true;
			case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOT:          return true;
			case sc2::UNIT_TYPEID::PROTOSS_TEMPLARARCHIVE:      return true;
			case sc2::UNIT_TYPEID::PROTOSS_TWILIGHTCOUNCIL:     return true;
			case sc2::UNIT_TYPEID::ZERG_ULTRALISKCAVERN:        return true;
			case sc2::UNIT_TYPEID::ZERG_HIVE:                   return true;
			case sc2::UNIT_TYPEID::ZERG_LAIR:                   return true;
			case sc2::UNIT_TYPEID::ZERG_GREATERSPIRE:           return true;
			case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMAND:       return true;
			case sc2::UNIT_TYPEID::TERRAN_PLANETARYFORTRESS:    return true;
			case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOTLOWERED:   return true;
			case sc2::UNIT_TYPEID::TERRAN_FACTORYFLYING:        return true;
			case sc2::UNIT_TYPEID::TERRAN_BARRACKSFLYING:       return true;
			case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTERFLYING:  return true;
			case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING: return true;
			case sc2::UNIT_TYPEID::TERRAN_STARPORTFLYING:       return true;
			case sc2::UNIT_TYPEID::TERRAN_TECHLAB:              return true;

			default: return false;
		}
	}
};

// --------------------------------------------------------
struct IsArmy 
{
	bool operator()(const sc2::Unit& unit)
	{
		switch (unit.unit_type.ToType())
		{
			case sc2::UNIT_TYPEID::TERRAN_BANSHEE: return true;
			case sc2::UNIT_TYPEID::TERRAN_BATTLECRUISER: return true;
			case sc2::UNIT_TYPEID::TERRAN_CYCLONE: return true;
			case sc2::UNIT_TYPEID::TERRAN_GHOST: return true;
			case sc2::UNIT_TYPEID::TERRAN_HELLION: return true;
			case sc2::UNIT_TYPEID::TERRAN_HELLIONTANK: return true;
			case sc2::UNIT_TYPEID::TERRAN_LIBERATOR: return true;
			case sc2::UNIT_TYPEID::TERRAN_LIBERATORAG: return true;
			case sc2::UNIT_TYPEID::TERRAN_MARAUDER: return true;
			case sc2::UNIT_TYPEID::TERRAN_MARINE: return true;
			case sc2::UNIT_TYPEID::TERRAN_MEDIVAC: return true;
			case sc2::UNIT_TYPEID::TERRAN_MULE: return true;
			case sc2::UNIT_TYPEID::TERRAN_RAVEN: return true;
			case sc2::UNIT_TYPEID::TERRAN_REAPER: return true;
			case sc2::UNIT_TYPEID::TERRAN_SCV: return true;
			case sc2::UNIT_TYPEID::TERRAN_SIEGETANK: return true;
			case sc2::UNIT_TYPEID::TERRAN_SIEGETANKSIEGED: return true;
			case sc2::UNIT_TYPEID::TERRAN_THOR: return true;
			case sc2::UNIT_TYPEID::TERRAN_THORAP: return true;
			case sc2::UNIT_TYPEID::TERRAN_VIKINGASSAULT: return true;
			case sc2::UNIT_TYPEID::TERRAN_VIKINGFIGHTER: return true;
			case sc2::UNIT_TYPEID::ZERG_BANELING: return true;
			case sc2::UNIT_TYPEID::ZERG_BROODLING: return true;
			case sc2::UNIT_TYPEID::ZERG_BROODLORD: return true;
			case sc2::UNIT_TYPEID::ZERG_BROODLORDCOCOON: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELING: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGMARINE: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGMARINESHIELD: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGZEALOT: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGZERGLING: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGZERGLINGWINGS: return true;
			case sc2::UNIT_TYPEID::ZERG_CORRUPTOR: return true;
			case sc2::UNIT_TYPEID::ZERG_DRONE: return true;
			case sc2::UNIT_TYPEID::ZERG_HYDRALISK: return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTEDTERRANSEGG: return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTOR: return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTORTERRAN: return true;
			case sc2::UNIT_TYPEID::ZERG_LOCUSTMP: return true;
			case sc2::UNIT_TYPEID::ZERG_LOCUSTMPFLYING: return true;
			case sc2::UNIT_TYPEID::ZERG_LURKERMP: return true;
			case sc2::UNIT_TYPEID::ZERG_MUTALISK: return true;
			case sc2::UNIT_TYPEID::ZERG_OVERLORD: return true;
			case sc2::UNIT_TYPEID::ZERG_OVERLORDTRANSPORT: return true;
			case sc2::UNIT_TYPEID::ZERG_OVERSEER: return true;
			case sc2::UNIT_TYPEID::ZERG_QUEEN: return true;
			case sc2::UNIT_TYPEID::ZERG_RAVAGER: return true;
			case sc2::UNIT_TYPEID::ZERG_ROACH: return true;
			case sc2::UNIT_TYPEID::ZERG_SPINECRAWLERUPROOTED: return true;
			case sc2::UNIT_TYPEID::ZERG_SPORECRAWLERUPROOTED: return true;
			case sc2::UNIT_TYPEID::ZERG_SWARMHOSTBURROWEDMP: return true;
			case sc2::UNIT_TYPEID::ZERG_SWARMHOSTMP: return true;
			case sc2::UNIT_TYPEID::ZERG_TRANSPORTOVERLORDCOCOON: return true;
			case sc2::UNIT_TYPEID::ZERG_ULTRALISK: return true;
			case sc2::UNIT_TYPEID::ZERG_VIPER: return true;
			case sc2::UNIT_TYPEID::ZERG_ZERGLING: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ADEPT: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ARCHON: return true;
			case sc2::UNIT_TYPEID::PROTOSS_CARRIER: return true;
			case sc2::UNIT_TYPEID::PROTOSS_COLOSSUS: return true;
			case sc2::UNIT_TYPEID::PROTOSS_DARKTEMPLAR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_DISRUPTOR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_HIGHTEMPLAR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_IMMORTAL: return true;
			case sc2::UNIT_TYPEID::PROTOSS_INTERCEPTOR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_MOTHERSHIP: return true;
			case sc2::UNIT_TYPEID::PROTOSS_MOTHERSHIPCORE: return true;
			case sc2::UNIT_TYPEID::PROTOSS_OBSERVER: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ORACLE: return true;
			case sc2::UNIT_TYPEID::PROTOSS_PHOENIX: return true;
			case sc2::UNIT_TYPEID::PROTOSS_PROBE: return true;
			case sc2::UNIT_TYPEID::PROTOSS_SENTRY: return true;
			case sc2::UNIT_TYPEID::PROTOSS_STALKER: return true;
			case sc2::UNIT_TYPEID::PROTOSS_TEMPEST: return true;
			case sc2::UNIT_TYPEID::PROTOSS_VOIDRAY: return true;
			case sc2::UNIT_TYPEID::PROTOSS_WARPPRISM: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ZEALOT: return true;

			default: return false;
		}
	}
};

// --------------------------------------------------------
struct IsGroundArmy 
{
	bool operator()(const sc2::Unit& unit)
	{
		switch (unit.unit_type.ToType())
		{
			case sc2::UNIT_TYPEID::TERRAN_BANSHEE: return true;
			case sc2::UNIT_TYPEID::TERRAN_BATTLECRUISER: return true;
			case sc2::UNIT_TYPEID::TERRAN_CYCLONE: return true;
			case sc2::UNIT_TYPEID::TERRAN_GHOST: return true;
			case sc2::UNIT_TYPEID::TERRAN_HELLION: return true;
			case sc2::UNIT_TYPEID::TERRAN_HELLIONTANK: return true;
			case sc2::UNIT_TYPEID::TERRAN_MARAUDER: return true;
			case sc2::UNIT_TYPEID::TERRAN_MARINE: return true;
			case sc2::UNIT_TYPEID::TERRAN_MULE: return true;
			case sc2::UNIT_TYPEID::TERRAN_REAPER: return true;
			case sc2::UNIT_TYPEID::TERRAN_SCV: return true;
			case sc2::UNIT_TYPEID::TERRAN_SIEGETANK: return true;
			case sc2::UNIT_TYPEID::TERRAN_SIEGETANKSIEGED: return true;
			case sc2::UNIT_TYPEID::TERRAN_THOR: return true;
			case sc2::UNIT_TYPEID::TERRAN_THORAP: return true;
			case sc2::UNIT_TYPEID::TERRAN_VIKINGASSAULT: return true;
			case sc2::UNIT_TYPEID::ZERG_BANELING: return true;
			case sc2::UNIT_TYPEID::ZERG_BROODLING: return true;
			case sc2::UNIT_TYPEID::ZERG_BROODLORDCOCOON: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELING: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGMARINE: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGMARINESHIELD: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGZEALOT: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGZERGLING: return true;
			case sc2::UNIT_TYPEID::ZERG_CHANGELINGZERGLINGWINGS: return true;
			case sc2::UNIT_TYPEID::ZERG_CORRUPTOR: return true;
			case sc2::UNIT_TYPEID::ZERG_DRONE: return true;
			case sc2::UNIT_TYPEID::ZERG_HYDRALISK: return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTEDTERRANSEGG: return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTOR: return true;
			case sc2::UNIT_TYPEID::ZERG_INFESTORTERRAN: return true;
			case sc2::UNIT_TYPEID::ZERG_LURKERMP: return true;
			case sc2::UNIT_TYPEID::ZERG_OVERLORD: return true;
			case sc2::UNIT_TYPEID::ZERG_OVERLORDTRANSPORT: return true;
			case sc2::UNIT_TYPEID::ZERG_OVERSEER: return true;
			case sc2::UNIT_TYPEID::ZERG_QUEEN: return true;
			case sc2::UNIT_TYPEID::ZERG_RAVAGER: return true;
			case sc2::UNIT_TYPEID::ZERG_ROACH: return true;
			case sc2::UNIT_TYPEID::ZERG_SPINECRAWLERUPROOTED: return true;
			case sc2::UNIT_TYPEID::ZERG_SPORECRAWLERUPROOTED: return true;
			case sc2::UNIT_TYPEID::ZERG_SWARMHOSTBURROWEDMP: return true;
			case sc2::UNIT_TYPEID::ZERG_SWARMHOSTMP: return true;
			case sc2::UNIT_TYPEID::ZERG_TRANSPORTOVERLORDCOCOON: return true;
			case sc2::UNIT_TYPEID::ZERG_ULTRALISK: return true;
			case sc2::UNIT_TYPEID::ZERG_ZERGLING: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ADEPT: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ARCHON: return true;
			case sc2::UNIT_TYPEID::PROTOSS_COLOSSUS: return true;
			case sc2::UNIT_TYPEID::PROTOSS_DARKTEMPLAR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_DISRUPTOR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_HIGHTEMPLAR: return true;
			case sc2::UNIT_TYPEID::PROTOSS_IMMORTAL: return true;
			case sc2::UNIT_TYPEID::PROTOSS_PROBE: return true;
			case sc2::UNIT_TYPEID::PROTOSS_SENTRY: return true;
			case sc2::UNIT_TYPEID::PROTOSS_STALKER: return true;
			case sc2::UNIT_TYPEID::PROTOSS_ZEALOT: return true;

			default: return false;
		}
	}
};

// --------------------------------------------------------
//! Does not include supply depots, pylons, overlords, etc.
struct IsTownHall 
{
	bool operator()(const sc2::Unit& unit) 
	{
		switch (unit.unit_type.ToType()) 
		{
			case sc2::UNIT_TYPEID::ZERG_HATCHERY: return true;
			case sc2::UNIT_TYPEID::ZERG_LAIR: return true;
			case sc2::UNIT_TYPEID::ZERG_HIVE: return true;
			case sc2::UNIT_TYPEID::TERRAN_COMMANDCENTER: return true;
			case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMAND: return true;
			case sc2::UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING: return true;
			case sc2::UNIT_TYPEID::TERRAN_PLANETARYFORTRESS: return true;
			case sc2::UNIT_TYPEID::PROTOSS_NEXUS: return true;

			default: return false;
		}
	}
};

// --------------------------------------------------------
//! Does not include town halls
struct IsSupply
{
	// I'm not sure at this time overlord cocoons are when an overlord
	//  is transforming into an overseer? Is it still an overlord at that time?
	
	bool operator()(const sc2::Unit& unit)
	{
		switch (unit.unit_type.ToType())
		{
		case sc2::UNIT_TYPEID::ZERG_OVERLORD: return true;
		case sc2::UNIT_TYPEID::ZERG_OVERSEER: return true;
		case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOT: return true;
		case sc2::UNIT_TYPEID::TERRAN_SUPPLYDEPOTLOWERED: return true;
		case sc2::UNIT_TYPEID::PROTOSS_PYLON: return true;

		default: return false;
		}
	}
};

// --------------------------------------------------------
struct IsVespeneGeyser
{
	bool operator()(const sc2::Unit& unit)
	{
		switch (unit.unit_type.ToType())
		{
			case sc2::UNIT_TYPEID::NEUTRAL_VESPENEGEYSER: return true;
			case sc2::UNIT_TYPEID::NEUTRAL_SPACEPLATFORMGEYSER: return true;
			case sc2::UNIT_TYPEID::NEUTRAL_PROTOSSVESPENEGEYSER: return true;

			default: return false;
		}
	}
};

// --------------------------------------------------------
struct IsWorker 
{
	bool operator()(const sc2::Unit& unit) 
	{
		switch (unit.unit_type.ToType()) 
		{
			case sc2::UNIT_TYPEID::PROTOSS_PROBE: return true;
			case sc2::UNIT_TYPEID::ZERG_DRONE: return true;
			case sc2::UNIT_TYPEID::TERRAN_SCV: return true;

			default: return false;
		}
	}
};

// --------------------------------------------------------
struct IsLarva
{
	bool operator()(const sc2::Unit& unit)
	{
		switch (unit.unit_type.ToType())
		{
		case sc2::UNIT_TYPEID::ZERG_LARVA: return true;

		default: return false;
		}
	}
};