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

// Forward Declarations -----------------------------------
class sc2::ObservationInterface;

// BenjiBot -----------------------------------------------
class BenjiBot : public sc2::Agent
{

public:

	// Placement Queries that the bot can perform;
	sc2::Point2D GetRandomBuildableLocationFor(sc2::ABILITY_ID structure, sc2::Point2D location, QueryType queryType, sc2::search::ExpansionParameters parameters);
	sc2::Point2D GetNearestBuildableLocationFor(sc2::ABILITY_ID structure, sc2::Point2D location, QueryType queryType, sc2::search::ExpansionParameters parameters = sc2::search::ExpansionParameters());
	
    // Helpers, may move these later;
    bool TryFindNearestUnitToPoint(const sc2::Point2D& point, const sc2::Units& units, uint64_t& nearestUnitId, float distance = std::numeric_limits<float>::max());
    bool TryFindNearestGeyserWithLessThanIdealHarvesters(const sc2::Point2D& point, uint64_t& nearestGeyserId, float distance);

    bool TryBuildGeyserStructureAtGeyser(uint64_t geyserId);

    // Constructor;
	BenjiBot();

    // Overrides from Agent;
	virtual void OnGameStart() override;
    virtual void OnStep() override;
    virtual void OnUnitIdle(const sc2::Unit* unit) override;
    virtual void OnUnitCreated(const sc2::Unit* unit) override;
    virtual void OnUnitDestroyed(const sc2::Unit* unit) override;
    virtual void OnUnitEnterVision(const sc2::Unit* unit) override;

private:

	int32_t GetCurrentMaxSupply();
    bool TryFindEnemyPosition(sc2::Point2D& targetPosition);
    bool TryFindRandomPathableLocation(const sc2::Tag tag, sc2::Point2D& targetPosition);

private:

    // Pointers to helpful interfaces so we don't have to retrieve them often;
    const sc2::ObservationInterface* m_observationInterface = nullptr;

    // Important Positions;
	sc2::Point3D m_startingPosition;
	std::vector<sc2::Point3D> m_expansionPositions;

    // Match Data;
	sc2::GameInfo* m_gameInfo;
	sc2::Race m_opponentRace;
};

void DllExport *CreateNewAgent();
int DllExport GetAgentRace();
const char DllExport *GetAgentName();