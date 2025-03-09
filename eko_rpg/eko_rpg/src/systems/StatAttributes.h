#pragma once
#include "../../src/types/CustomTypes.h"

class StatAttributes
{
private:
	ui16 Strength;
	ui16 Intelligience;
	ui16 Agility;
	ui16 Armor;
	ui16 Resistance;
protected:
	void IncreaseStats(ui16 str, ui16 itg, ui16 agi, ui16 arm = 0u, ui16 res = 0u);
public:

	StatAttributes() { Strength = 0u; Intelligience = 0u; Agility = 0u; Armor = 0u; Resistance = 0u;}
	explicit StatAttributes(ui16 str = 0u, ui16 itg = 0u, ui16 agi = 0u, ui16 arm = 0u, ui16 res = 0u) { Strength = str; Intelligience = itg; Agility = agi; Armor = arm; Resistance = res;}

	ui16 GetStrength() { return Strength;  }
	ui16 GetIntelligience() { return Intelligience; }
	ui16 GetAgility() { return Agility; }
	ui16 GetArmor() { return Armor; }
	ui16 GetResistance() { return Resistance; }
};

