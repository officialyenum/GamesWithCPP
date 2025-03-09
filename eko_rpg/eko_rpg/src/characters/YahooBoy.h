#pragma once

#include "../systems/PlayerCharacterSystem.h"
#include "../utilities/CustomMacros.h"

class YahooBoy : public PlayerCharacterSystem
{

public:

	static const ui16 BaseHp = (ui16)19u;
	static const ui16 BaseMp = (ui16)10;
	static const ui16 BaseStr = (ui16)4u;
	static const ui16 BaseInt = (ui16)1u;
	static const ui16 BaseAgi = (ui16)1u;
	static const ui16 BaseArm = (ui16)0u;
	static const ui16 BaseRes = (ui16)0u;
	YahooBoy() : PlayerCharacterSystem() {
		PCCONSTRUCT
	}
	std::string GetClassName() { return std::string("YahooBoy"); }

private:
	// Inherited via LevelUpSystem
	void LevelUp() override {
		PCLEVELUP
	}

};

