#pragma once
#include "../src/equipments/Equipment.h"
#include "../src/systems/PointWellSystem.h"
#include "../src/systems/StatAttributes.h"
#include "../src/systems/PlayerCharacterSystem.h"


class Character
{

private:
	PlayerCharacterSystem* PCS;
	Equipment* EquippedArmors[(unsigned long long)EArmorSlot::NUM_SLOTS];
	Equipment* EquippedWeapons[(unsigned long long)EWeaponSlot::NUM_SLOTS];

public:

	Character() = delete;
	Character(const PlayerCharacterSystem&) = delete;
	Character(const PlayerCharacterSystem&&) = delete;

	Character(PlayerCharacterSystem* pcs) : PCS(pcs) {
		auto i = 0;
		for (i = 0; i < (unsigned long long)EArmorSlot::NUM_SLOTS; i++)
		{
			EquippedArmors[i] = nullptr;
		}
		for (i = 0; i < (unsigned long long)EWeaponSlot::NUM_SLOTS; i++)
		{
			EquippedWeapons[i] = nullptr;
		}
	}
	~Character() { 
		delete PCS; 
		PCS = nullptr;

		auto i = 0;
		for (i = 0; i < (unsigned long long)EArmorSlot::NUM_SLOTS; i++)
		{
			if (EquippedArmors[i])
			{
				delete EquippedArmors[i];
				EquippedArmors[i] = nullptr;
			}
		}
		for (i = 0; i < (unsigned long long)EWeaponSlot::NUM_SLOTS; i++)
		{
			if (EquippedWeapons[i])
			{
				delete EquippedWeapons[i];
				EquippedWeapons[i] = nullptr;
			}
		}
	}

	// class
	std::string GetClassName() { return PCS->GetClassName(); }
	std::vector<Ability> GetAbilities() { return PCS->Abilities; }
	std::vector<Buff> GetBuffs() { return PCS->Buffs; }

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

	ui64 GetBaseStrength() { return PCS->GetBaseStrength(); }
	ui64 GetBaseIntelligience() { return PCS->GetBaseIntelligience(); }
	ui64 GetBaseAgility() { return PCS->GetBaseAgility(); }
	ui64 GetBaseArmor() { return PCS->GetBaseArmor(); }
	ui64 GetBaseResistance() { return PCS->GetBaseResistance(); }
	// Stats Setters
	
	
	// Well Points Getters
	ui16 GetCurrentHP() { return PCS->HP->GetCurrent(); }
	ui16 GetMaxHP() { return PCS->HP->GetMax(); }
	ui16 GetCurrentMP() { 
		if (PCS->MP)
			return PCS->MP->GetCurrent(); 
		return 0;
	}
	ui16 GetMaxMP() {
		if (PCS->MP)
			return PCS->MP->GetMax();
		return 0; 
	}

	// Well Points Setters
	void TakeDamage(ui16 damage) { PCS->HP->Reduce(damage); }
	void Heal(ui16 amount) { PCS->HP->Increase(amount); }
	void UseJazz(ui16 amount) { PCS->MP->Reduce(amount); }
	void PowerUpJazz(ui16 amount) { PCS->MP->Increase(amount); }

	// Buff Functions
	void ApplyBuff(Buff buff) { PCS->ApplyBuff(buff); }

	// Equipment Functions
	Equipment* GetEquippedArmorAt(ui16 index) { return EquippedArmors[index]; }
	Equipment* GetEquippedWeaponAt(ui16 index) { return EquippedWeapons[index]; }
	bool Equip(Equipment* thing)
	{
		Armor* armor = dynamic_cast<Armor*>(thing);
		if (armor)
		{
			//equip armor
			unsigned long long slotNum = (unsigned long long)armor->Slot;
			if (EquippedArmors[slotNum])
			{
				delete EquippedArmors[slotNum];
				EquippedArmors[slotNum] = nullptr;
				EquippedArmors[slotNum] = armor;
			}
			else {
				EquippedArmors[slotNum] = armor;
			}
			return true;
		}
		Weapon* weapon = dynamic_cast<Weapon*>(thing);
		if (weapon)
		{
			//equip weapon
			unsigned long long slotNum = (unsigned long long)weapon->Slot;
			if (EquippedWeapons[slotNum])
			{
				delete EquippedWeapons[slotNum];
				EquippedWeapons[slotNum] = nullptr;
				EquippedWeapons[slotNum] = weapon;
			}
			else {
				EquippedWeapons[slotNum] = weapon;
			}
			return true;
		}
		return false;
	}
};

