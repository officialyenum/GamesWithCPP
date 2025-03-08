#pragma once
#include "../src/systems/PointWellSystem.h"
#include "../src/systems/StatAttributes.h"
#include "../src/systems/PlayerCharacterSystem.h"


class Character
{

private:
	PlayerCharacterSystem* PCS;

public:

	Character() = delete;
	Character(PlayerCharacterSystem* pcs) : PCS(pcs) {}
	~Character() { delete PCS; PCS = nullptr; }

	// class

	std::string GetClassName() { return PCS->GetClassName(); }

	// levels Getters

	ui16 GetCurrentLevel() { return PCS->GetCurrentLevel(); }
	ui64 GetCurrentXP() { return PCS->GetCurrentXP(); }
	ui64 GetXpToNextLevel() { return PCS->GetXpToNextLevel(); }

	// levels Setters
	void GainEXP(ui16 gainedXP) { PCS->GainEXP(gainedXP); }

	// Stats Getters
	ui64 GetStrength() { return PCS->GetStrength(); }
	ui64 GetIntelligience() { return PCS->GetIntelligience(); }
	ui64 GetAgility() { return PCS->GetAgility(); }
	ui64 GetArmor() { return PCS->GetArmor(); }
	ui64 GetResistance() { return PCS->GetResistance(); }
	// Stats Setters
	
	
	// Well Points Getters
	ui16 GetCurrentHP() { return PCS->HP->GetCurrent(); }
	ui16 GetMaxHP() { return PCS->HP->GetMax(); }

	// Well Points Setters
	void TakeDamage(ui16 damage) { PCS->HP->Reduce(damage); }
	void Heal(ui16 amount) { PCS->HP->Increase(amount); }
};

