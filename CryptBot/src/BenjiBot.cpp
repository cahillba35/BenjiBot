#include "BenjiBot.hpp"

#include "sc2api/sc2_api.h"

#include "Queries/UnitTypeQueries.hpp"

#include <iostream>

// --------------------------------------------------------
// Bot Only Functionality
// --------------------------------------------------------
size_t CalculateQueries(float radius, float circumferenceDegreeStepSize, const sc2::Point2D& center, sc2::ABILITY_ID structure, QueryType queryType, std::vector<sc2::QueryInterface::PlacementQuery>& placementQueries)
{
	sc2::Point2D currentGrid;
	sc2::Point2D previousGrid(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
	size_t validQueries = 0;

	// Find a buildable location on the circumference of the circle;
	float degreesLocation = 0.0f;
	while (degreesLocation < 360.0f)
	{
		// Convert degrees of our circle to radians;
		float radians = (degreesLocation * PI) / 180.0f;
		float x = radius * std::cos(radians) + center.x;
		float y = radius * std::sin(radians) + center.y;
		sc2::Point2D circumferencePoint = sc2::Point2D(x, y);

		// We can only be one type of queryType per query, so find which we are;
		// We will only except a point in our desired region;
		switch (queryType)
		{
			case MaxXMinY:
			{
				if (circumferencePoint.x > center.x || circumferencePoint.y < center.y)
				{
					degreesLocation += circumferenceDegreeStepSize;
					continue;
				}
				break;
			}
			case MaxXMaxY:
			{
				if (circumferencePoint.x > center.x || circumferencePoint.y > center.y)
				{
					degreesLocation += circumferenceDegreeStepSize;
					continue;
				}
				break;
			}
			case MinXMinY:
			{
				if (circumferencePoint.x < center.x || circumferencePoint.y > center.y)
				{
					degreesLocation += circumferenceDegreeStepSize;
					continue;
				}
				break;
			}
			case MinXMaxY:
			{
				if (circumferencePoint.x < center.x || circumferencePoint.y < center.y)
				{
					degreesLocation += circumferenceDegreeStepSize;
					continue;
				}
				break;
			}
		}

		// Check to see if this circumference point is a different grid than our potential last circumference point;
		float gridX = floor(circumferencePoint.x);
		float gridY = floor(circumferencePoint.y);
		currentGrid = sc2::Point2D(gridX, gridY);
		if (currentGrid != previousGrid)
		{
			// Make a placement query for the passed circumference point;
			sc2::QueryInterface::PlacementQuery placementQuery(structure, circumferencePoint);
			placementQueries.push_back(placementQuery);
			validQueries++;
		}

		previousGrid = currentGrid;
		degreesLocation += circumferenceDegreeStepSize;
	}

	return validQueries;
}

// --------------------------------------------------------
// These are accessible by asking the bot to perform
// --------------------------------------------------------
sc2::Point2D BenjiBot::GetRandomBuildableLocationFor(sc2::ABILITY_ID structure, sc2::Point2D location, QueryType queryType, sc2::search::ExpansionParameters parameters)
{
	std::vector<sc2::QueryInterface::PlacementQuery> desiredPlacementQueries;
	std::vector<sc2::QueryInterface::PlacementQuery> validPlacementQueries;

	// Populate desiredPlacementQueries with potential placements based on desires;
	for (float radius : parameters.radiuses_)
	{
		CalculateQueries(radius, parameters.circle_step_size_, location, structure, queryType, desiredPlacementQueries);
	}

	// Check our desires against what is valid in game;
	std::vector<bool> placementResults = Query()->Placement(desiredPlacementQueries);
	for (size_t i = 0; i < placementResults.size(); i++)
	{
		if (placementResults[i])
		{
			validPlacementQueries.push_back(desiredPlacementQueries[i]);
		}
	}

	// Determine the return placement location;
	sc2::Point2D placementLocation;
	if (validPlacementQueries.size() < 1)
	{
		// We will let the game handle the potential placement error;
		std::cout << "No valid placement locations \n";
	}

	// Get a ref to a random placement and use its location;
	sc2::QueryInterface::PlacementQuery& randomPlacement = GetRandomEntry(validPlacementQueries);
	placementLocation = randomPlacement.target_pos;

	return placementLocation;
}

// --------------------------------------------------------
sc2::Point2D BenjiBot::GetNearestBuildableLocationFor(sc2::ABILITY_ID structure, sc2::Point2D location, QueryType queryType, sc2::search::ExpansionParameters parameters /*= sc2::search::ExpansionParameters()*/)
{
	std::vector<sc2::QueryInterface::PlacementQuery> desiredPlacementQueries;

	// Populate desiredPlacementQueries with potential placements based on desires;
	for (float radius : parameters.radiuses_)
	{
		CalculateQueries(radius, parameters.circle_step_size_, location, structure, queryType, desiredPlacementQueries);
	}

	// Check our desires against what is valid in game, keeping track of the closest;
	std::vector<bool> placementResults = Query()->Placement(desiredPlacementQueries);
	float distance = std::numeric_limits<float>::max();
	sc2::Point2D closestPlacementPosition;
	for (size_t i = 0; i < placementResults.size(); i++)
	{
		if (placementResults[i])
		{
			sc2::Point2D& p = desiredPlacementQueries[i].target_pos;			
			float d = Distance2D(p, location);
			if (d < distance)
			{
				distance = d;
				closestPlacementPosition = p;
			}
		}
	}

	return closestPlacementPosition;
}

// --------------------------------------------------------
// Constructor
// --------------------------------------------------------
BenjiBot::BenjiBot()
{

}

// --------------------------------------------------------
void BenjiBot::OnGameStart()
{
	// Determine Opponentt's race, only support 1 opponent race;
	m_gameInfo = new sc2::GameInfo(Observation()->GetGameInfo());

	// If we find any race to be ours, then the other race must be opponent;
	bool ownRaceFound = false;
	for (const auto& info : m_gameInfo->player_info)
	{
		if (info.race_actual == sc2::Race::Zerg && ownRaceFound == false)
		{
			ownRaceFound = true;
			continue;
		}

		m_opponentRace = info.race_actual;
	}

	// This is not working, I am not getting any units.
	// Is this function firing too early?
	// Can we add a sleep somewhere for 1ms?
	// No, we cannot sleep.
	// Maybe dont tell units to do things in the game startup
	// When you come back, look into moving this below code into OnStep()

	// On start of the game, there is only 1 hatchery;
	const sc2::Units hatcheries = Observation()->GetUnits();
	const sc2::Units NewUnits = Observation()->GetUnits();
	m_startingPosition = sc2::Point3D(hatcheries[0]->pos);

	// Just tell all of the starting larva to build a drone, only 1 will work;
	const sc2::Units larvas = Observation()->GetUnits(sc2::Unit::Alliance::Ally, IsLarva());
	Actions()->UnitCommand(larvas, sc2::ABILITY_ID::TRAIN_DRONE);

	m_expansionLocations = sc2::search::CalculateExpansionLocations(Observation(), Query());
	
}

// --------------------------------------------------------
int32_t BenjiBot::GetCurrentMaxSupply()
{
	int32_t maxSupply = 0;
	const sc2::Units townHalls = Observation()->GetUnits(sc2::Unit::Alliance::Ally, IsTownHall());
	const sc2::Units supplys = Observation()->GetUnits(sc2::Unit::Alliance::Ally, IsSupply());

	for (const auto& townHall : townHalls)
	{
		maxSupply += 15;
	}
	for (const auto& supply : supplys)
	{
		maxSupply += 8;
	}

	return maxSupply;
}
