#pragma once
#include <string>
#include "../../src/types/CustomTypes.h"

enum class EAbilityTarget {
	SELF,
	ENEMY,
	ALLY,
};

enum class EAbilityScalar {
	NONE,
	STR,
	AGI,
	INT,
};

struct Ability {
	Ability(std::string n, ui32 c, ui32 cd, EAbilityTarget t, ui32 hfx, EAbilityScalar s) :
		Name(n), Cost(c), Cooldown(cd), Target(t), HpEffects(hfx), Scaler(s)
	{
	}
	std::string Name = "unnamed";
	ui32 Cost = 0;
	ui32 Cooldown = 1;
	EAbilityTarget Target = EAbilityTarget::SELF;
	ui32 HpEffects = 1;
	EAbilityScalar Scaler = EAbilityScalar::NONE;
};