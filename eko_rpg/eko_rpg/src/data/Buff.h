#pragma once
#include <string>
#include "../../src/types/CustomTypes.h"
#include "CoreStat.h"


struct Buff {
	Buff(const char* name, ui16 str = 0, ui16 itg = 0, ui16 agi = 0, ui16 arm = 0, ui16 res = 0, ui16 dur = 2u, bool isDebuff = false) :
		Name(name), 
		Duration(dur),
		bIsDebuff(isDebuff)
	{
		BuffedStats.Strength = str;
		BuffedStats.Intelligience = itg;
		BuffedStats.Agility = agi;
		BuffedStats.Armor = arm;
		BuffedStats.Resistance = res;
	}
	Buff(const char* name, CoreStat bs, ui16 dur = 2u, bool isDebuff = false) :
		Name(name),
		Duration(dur),
		bIsDebuff(isDebuff)
	{
		BuffedStats = bs;
	}
	std::string Name="unnamed";
	ui16 Duration = 0;
	CoreStat BuffedStats;
	bool bIsDebuff;
};