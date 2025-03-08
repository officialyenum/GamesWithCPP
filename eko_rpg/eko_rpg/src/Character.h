#pragma once
#include "../src/systems/HitPointSystem.h"
#include "../src/systems/StatAttributes.h"

class Character: public HitPointSystem, public StatAttributes
{
private:
public:
	static const HpType HpGrowth = (HpType)19u;
	static const StatType BaseStr = (StatType)4u;
	static const StatType BaseInt = (StatType)1u;
	Character() : HitPointSystem(HpGrowth, HpGrowth), StatAttributes(BaseStr, BaseInt) {};
};

