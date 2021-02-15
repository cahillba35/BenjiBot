#pragma once

// sc2api includes ----------------------------------------
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_map_info.h"
#include "sc2lib/sc2_lib.h"

// Includes -----------------------------------------------
#include "BotCommon.hpp"

// BenjiBot -----------------------------------------------
class BenjiBot : public Agent
{

public:

	BenjiBot();

	virtual void OnGameStart() override;

};