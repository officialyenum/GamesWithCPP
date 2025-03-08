#pragma once
#include "../../src/types/CustomTypes.h"

class StatAttributes
{
private:
	StatType Strength;
	StatType Intellect;
public:

	StatAttributes() { Strength = (StatType)1u; Intellect = (StatType)1u; }
	explicit StatAttributes(StatType s, StatType i) { Strength = s; Intellect = i; }

	StatType GetStrength() { return Strength;  }
	StatType GetIntellect() { return Intellect; }
};

