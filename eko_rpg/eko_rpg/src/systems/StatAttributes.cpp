#include "StatAttributes.h"

void StatAttributes::RecalculateBuffs()
{
	CoreStat tmp_total;
	for (auto& buffItem : Buffs)
	{
		if (buffItem.bIsDebuff) {
			tmp_total -= buffItem.BuffedStats;
		} else {
			tmp_total += buffItem.BuffedStats;
		}
	}
	s_BaseFromBuffs = tmp_total;
}

void StatAttributes::IncreaseStats(ui16 str, ui16 itg, ui16 agi, ui16 arm, ui16 res)
{
	s_Base.Strength += str;
	s_Base.Intelligience += itg;
	s_Base.Agility += agi;
	s_Base.Armor += arm;
	s_Base.Resistance += res;
}

void StatAttributes::IncreaseStats(CoreStat cs)
{
	s_Base += cs;
}

void StatAttributes::AddNewBuff(Buff buff)
{
	for (auto& buffItem : Buffs)
	{
		if (buff.Name == buffItem.Name) {
			buffItem.Duration = buff.Duration;
			return;
		}
	}
	Buffs.push_back(buff);
	RecalculateBuffs();
}
