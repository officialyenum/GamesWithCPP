#include <iostream>
#include "src/Character.h"

int main() {
	Character ChiefPriest;

	std::cout << "Chief Priest\n"
		<< "-MaxHP: " << ChiefPriest.GetMaxHP() << '\n'
		<< "-Strength: " << ChiefPriest.GetStrength() << '\n'
		<< "-Intellect: " << ChiefPriest.GetIntellect() << '\n';
	return 0;
}