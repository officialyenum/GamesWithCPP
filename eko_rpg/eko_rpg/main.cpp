#include <iostream>
#include "src/Character.h"
#include "src/characters/PlayerList.h"

int main() {
	Character player(new ChiefPriest());


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
		if (i < 1)
			player.GainEXP(150u);
		
	}

	return 0;
}