#pragma once

// sc2api includes ----------------------------------------
#include "sc2api/sc2_interfaces.h"
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_map_info.h"
#include "sc2lib/sc2_lib.h"

// Includes -----------------------------------------------
#include "BotCommon.hpp"

// --------------------------------------------------------
#define DllExport   __declspec( dllexport )

// Placement Query Type -----------------------------------
enum QueryType
{
	None,
	MinXMinY,
	MinXMaxY,
	MaxXMinY,
	MaxXMaxY
};

// BenjiBot -----------------------------------------------
class BenjiBot : public sc2::Agent
{

public:

	// Placement Queries that the bot can perform;
	sc2::Point2D GetRandomBuildableLocationFor(sc2::ABILITY_ID structure, sc2::Point2D location, QueryType queryType, sc2::search::ExpansionParameters parameters);
	sc2::Point2D GetNearestBuildableLocationFor(sc2::ABILITY_ID structure, sc2::Point2D location, QueryType queryType, sc2::search::ExpansionParameters parameters = sc2::search::ExpansionParameters());
	
	BenjiBot();
	virtual void OnGameStart() override;

private:

	int32_t GetCurrentMaxSupply();

private:

	sc2::Point3D m_startingPosition;
	std::vector<sc2::Point3D> m_expansionLocations;

	sc2::GameInfo* m_gameInfo;
	sc2::Race m_opponentRace;
};