#include <iostream>
#include "src/Character.h"
#include "src/characters/PlayerList.h"

int main() {
	Character player(new ChiefPriest());

	{
		CoreStat plateArmorStats;
		plateArmorStats.Armor = 5;
		plateArmorStats.Resistance = 5;
		Armor* FullPlateMail = new Armor("Rage Plate Armor", plateArmorStats, EArmorSlot::CHEST);
		player.Equip(FullPlateMail);


		CoreStat sacredStaffStats;
		sacredStaffStats.Strength = 5;
		sacredStaffStats.Agility = 5;
		Weapon* SacredStaff = new Weapon("Sacred Staff Stats", sacredStaffStats, EWeaponSlot::MEELE1H, 5u, 8u);
		player.Equip(SacredStaff);
	};

	for (int i = 0; i < 2; i++)
	{
		std::cout << "Player \n" << player.GetClassName() << "\n"
			<< "-HP: " << player.GetCurrentHP() << " / " << player.GetMaxHP() << '\n'
			<< "-MP: " << player.GetCurrentMP() << " / " << player.GetMaxMP() << '\n'
			<< "-Strength: " << player.GetStrength() << '\n'
			<< "-Intelligience: " << player.GetIntelligience() << '\n'
			<< "-Agility: " << player.GetAgility() << '\n'
			<< "-Armor: " << player.GetArmor() << '\n'
			<< "-Resistance: " << player.GetResistance() << '\n'
			<< "-Level: " << player.GetCurrentLevel() << '\n'
			<< "-Exp: " << player.GetCurrentXP() << " / " << player.GetXpToNextLevel() << '\n';
		std::cout << "-Abilities: \n";
		for (auto& abil : player.GetAbilities())
		{
			std::cout << "  -" << abil.Name << "\n";
		}

		std::cout << "-Buffs: \n";
		for (auto& buff : player.GetBuffs())
		{
			std::cout << "  -" << buff.Name << "\n";
		}
		if (i < 1) {
			player.GainEXP(150u);
			Buff armorBuff("Stone Shield", 10, 0, 0, 0, 5u, 0);
			player.ApplyBuff(armorBuff);
		}

		std::cout << "-Armors: \n";
		for (ui16 i = 0; i < (ui16)EArmorSlot::NUM_SLOTS; i++)
		{
			const Armor* tmp = dynamic_cast<Armor*>(player.GetEquippedArmorAt(i));
			if(tmp) {
				std::cout << "  -Name: " << tmp->Name << "\n";
				std::cout << "  -Armor: " << tmp->Stats.Armor << "\n";
			}
		}
		std::cout << "-Weapons: \n";
		for (ui16 i = 0; i < (ui16)EWeaponSlot::NUM_SLOTS; i++)
		{
			const Weapon* tmp = dynamic_cast<Weapon*>(player.GetEquippedWeaponAt(i));
			if (tmp) {
				std::cout << "  -Name: " << tmp->Name << "\n";
				std::cout << "  -Strength: " << tmp->Stats.Strength << "\n";
			}
		}
		
	}

	return 0;
}