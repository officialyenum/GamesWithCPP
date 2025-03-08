#include "StatAttributes.h"

void StatAttributes::IncreaseStats(ui16 str, ui16 itg, ui16 agi, ui16 arm, ui16 res)
{
	Strength += str;
	Intelligience += itg;
	Agility += agi;
	Armor += arm;
	Resistance += res;
}
