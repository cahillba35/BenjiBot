#pragma once

#include "sc2lib/sc2_lib.h"

class ControlGroup
{

public:

	ControlGroup();
	~ControlGroup();


private:

	sc2::UNIT_TYPEID UnitType;
	std::vector<int64_t> Members;
	bool Attacking;
	uint64_t engaged_tag;
	sc2::Point2D ScoutingTarget;
};