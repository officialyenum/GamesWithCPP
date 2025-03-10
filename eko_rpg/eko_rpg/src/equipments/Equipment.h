#pragma once
#include <string>
#include <typeinfo>
#include "../data/CoreStat.h"

enum class EArmorSlot
{
	HELMET, CHEST, LEGS, BOOTS, GLOVES, RING1, RING2, NECK, NUM_SLOTS
};// NUM SLOTS Used for getting length

enum class EWeaponSlot
{
	MEELE1H, MEELE2H, RANGED, NUM_SLOTS
};// NUM SLOTS Used for getting length

class Equipment {
protected:
	Equipment() {};
	Equipment(std::string name, CoreStat cs) : Name(name), Stats(cs) {}
public:
	virtual const char* GetType() = 0;
	std::string Name;
	CoreStat Stats;
};


class Armor : public Equipment {
public:
	Armor() = delete;
	Armor(const Armor&) = delete;
	Armor(const Armor&&) = delete;

	Armor(std::string name, CoreStat cs, EArmorSlot slot) : Equipment(name, cs), Slot(slot) {}
	// Inherited via Equipment
	const char* GetType() override { return typeid(*this).name(); };
	EArmorSlot Slot;
};


class Weapon : public Equipment {
public:
	Weapon() = delete;
	Weapon(const Weapon&) = delete;
	Weapon(const Weapon&&) = delete;
	bool bIs2Hand;
	Weapon(std::string name, CoreStat cs, EWeaponSlot slot, ui16 min, ui16 max, bool twoHanded = false) : Equipment(name, cs), Slot(slot), MinDamage(min), MaxDamage(max), bIs2Hand(twoHanded) {}
	// Inherited via Equipment
	const char* GetType() override { return typeid(*this).name(); };
	EWeaponSlot Slot;
	ui16 MinDamage;
	ui16 MaxDamage;
};
