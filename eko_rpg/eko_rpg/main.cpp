#include <iostream>
#include "src/Character.h"
#include "src/characters/Agbero.h"

int main() {
	Character player(new Agbero());


	std::cout << "Player \n" << player.GetClassName() << "\n"
		<< "-HP: " << player.GetCurrentHP() << " / " << player.GetMaxHP() << '\n'
		<< "-Strength: " << player.GetStrength() << '\n'
		<< "-Intellect: " << player.GetIntelligience() << '\n'
		<< "-Agility: " << player.GetAgility() << '\n'
		<< "-Armor: " << player.GetArmor() << '\n'
		<< "-Resistance: " << player.GetResistance() << '\n'
		<< "-Level: " << player.GetCurrentLevel() << '\n'
		<< "-Exp: " << player.GetCurrentXP() << " / " << player.GetXpToNextLevel() << '\n';
	player.GainEXP(150u);

	std::cout << "Player \n" << player.GetClassName() << "\n"
		<< "-HP: " << player.GetCurrentHP() << " / " << player.GetMaxHP() << '\n'
		<< "-Strength: " << player.GetStrength() << '\n'
		<< "-Intellect: " << player.GetIntelligience() << '\n'
		<< "-Agility: " << player.GetAgility() << '\n'
		<< "-Armor: " << player.GetArmor() << '\n'
		<< "-Resistance: " << player.GetResistance() << '\n'
		<< "-Level: " << player.GetCurrentLevel() << '\n'
		<< "-Exp: " << player.GetCurrentXP() << " / " << player.GetXpToNextLevel() << '\n';
	return 0;
}