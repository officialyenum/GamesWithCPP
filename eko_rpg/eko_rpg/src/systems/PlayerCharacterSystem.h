#pragma once
#include <cstdint>
#include <memory>
#include "../../src/types/CustomTypes.h"
#include "PointWellSystem.h"
#include "StatAttributes.h"
#include <string>
#include <vector>
#include "../data/Ability.h"


class PlayerCharacterSystem: public StatAttributes
{

protected:
	ui16 CurrentLevel;
	ui64 CurrentXP;
	ui64 XpToNextLevel;

public:
	static const ui64 LEVEL2AT = 100u;
	static const ui16 LEVELSCALAR = 2u;
	std::unique_ptr<PointWellSystem> HP;
	std::unique_ptr<PointWellSystem> MP;

	PlayerCharacterSystem() : StatAttributes(0u, 0u, 0u, 0u, 0u), CurrentLevel{ 1u }, CurrentXP{ 0u }, XpToNextLevel{ LEVEL2AT }
	{
		HP = std::make_unique<PointWellSystem>(1u, 1u);
	}

	void GainEXP(ui16 gainedXP);
	void ApplyBuff(Buff buff);
	bool CheckIfLeveled();

	virtual void LevelUp() = 0;
	virtual std::string GetClassName() = 0;
	ui16 GetCurrentLevel() { return CurrentLevel;  }
	ui64 GetCurrentXP() { return CurrentXP; }
	ui64 GetXpToNextLevel() { return XpToNextLevel; }

	std::vector<Ability> Abilities;
};

