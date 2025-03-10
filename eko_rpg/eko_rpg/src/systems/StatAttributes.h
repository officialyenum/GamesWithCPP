#pragma once
#include "../../src/types/CustomTypes.h"
#include "../data/Buff.h"
#include <vector>
#include "../data/CoreStat.h"

class StatAttributes
{
private:
	CoreStat s_Base;
	CoreStat s_BaseFromBuffs;

	void RecalculateBuffs();
protected:
	void IncreaseStats(ui16 str, ui16 itg, ui16 agi, ui16 arm = 0u, ui16 res = 0u);
	void IncreaseStats(CoreStat cs);
	void AddNewBuff(Buff buff);
public:

	StatAttributes() { s_Base.Strength = 0u; s_Base.Intelligience = 0u; s_Base.Agility = 0u; s_Base.Armor = 0u; s_Base.Resistance = 0u; }
	explicit StatAttributes(ui16 str = 0u, ui16 itg = 0u, ui16 agi = 0u, ui16 arm = 0u, ui16 res = 0u) { 
		s_Base.Strength = str; 
		s_Base.Intelligience = itg; 
		s_Base.Agility = agi; 
		s_Base.Armor = arm; 
		s_Base.Resistance = res;
	}
	
	ui16 GetStrength() { return s_Base.Strength + s_BaseFromBuffs.Strength; }
	ui16 GetIntelligience() { return s_Base.Intelligience + s_BaseFromBuffs.Intelligience; }
	ui16 GetAgility() { return s_Base.Agility + s_BaseFromBuffs.Agility; }
	ui16 GetArmor() { return s_Base.Armor + s_BaseFromBuffs.Armor; }
	ui16 GetResistance() { return s_Base.Resistance + s_BaseFromBuffs.Resistance; }

	ui16 GetBaseStrength() { return s_Base.Strength; }
	ui16 GetBaseIntelligience() { return s_Base.Intelligience; }
	ui16 GetBaseAgility() { return s_Base.Agility; }
	ui16 GetBaseArmor() { return s_Base.Armor; }
	ui16 GetBaseResistance() { return s_Base.Resistance; }

	ui16 GetTotalStrengthFromBuffs() { return s_BaseFromBuffs.Strength; }
	ui16 GetTotalIntelligienceFromBuffs() { return s_BaseFromBuffs.Intelligience; }
	ui16 GetTotalAgilityFromBuffs() { return s_BaseFromBuffs.Agility; }
	ui16 GetTotalArmorFromBuffs() { return s_BaseFromBuffs.Armor; }
	ui16 GetTotalResistanceFromBuffs() { return s_BaseFromBuffs.Resistance; }

	std::vector<Buff> Buffs;
};

