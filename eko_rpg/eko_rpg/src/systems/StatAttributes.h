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

	StatAttributes() { Strength = (ui16)1u; Intelligience = (ui16)1u; Agility = (ui16)1u; Armor = (ui16)0u; Resistance = (ui16)0u;}
	explicit StatAttributes(ui16 str = 1u, ui16 itg = 1u, ui16 agi = 1u, ui16 arm = 0u, ui16 res = 0u) { Strength = str; Intelligience = itg; Agility = agi; Armor = arm; Resistance = res;}

	ui16 GetStrength() { return Strength;  }
	ui16 GetIntelligience() { return Intelligience; }
	ui16 GetAgility() { return Agility; }
	ui16 GetArmor() { return Armor; }
	ui16 GetResistance() { return Resistance; }
};

