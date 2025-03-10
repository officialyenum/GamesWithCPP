#pragma once
#include "../../src/types/CustomTypes.h"

struct CoreStat {

	ui16 Strength		= 0;
	ui16 Intelligience	= 0;
	ui16 Agility		= 0;
	ui16 Armor			= 0;
	ui16 Resistance		= 0;

	CoreStat& operator+=(const CoreStat& rhs) {
		this->Strength		+= rhs.Strength;
		this->Intelligience += rhs.Intelligience;
		this->Agility		+= rhs.Agility;
		this->Armor			+= rhs.Armor;
		this->Resistance	+= rhs.Resistance;
		return *this;
	}

	CoreStat& operator-=(const CoreStat& rhs) {
		CoreStat tmp = *this;

		this->Strength		-= rhs.Strength;
		this->Intelligience -= rhs.Intelligience;
		this->Agility		-= rhs.Agility;
		this->Armor			-= rhs.Armor;
		this->Resistance	-= rhs.Resistance;

		if (this->Strength > tmp.Strength) this->Strength = 0u;
		if (this->Intelligience > tmp.Intelligience) this->Intelligience = 0u;
		if (this->Agility > tmp.Agility) this->Agility = 0u;
		if (this->Armor > tmp.Armor) this->Armor = 0u;
		if (this->Resistance > tmp.Resistance) this->Resistance = 0u;
		
		return *this;
	}

	CoreStat& operator=(const ui16& rhs) {
		this->Strength = rhs;
		this->Intelligience = rhs;
		this->Agility = rhs;
		this->Armor = rhs;
		this->Resistance = rhs;
		return *this;
	}
};