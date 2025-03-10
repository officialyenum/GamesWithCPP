#include "PlayerCharacterSystem.h"

bool PlayerCharacterSystem::CheckIfLeveled()
{
	if (CurrentXP > XpToNextLevel)
	{
		CurrentLevel++;
		LevelUp();
		XpToNextLevel *= LEVELSCALAR;
		return true;
	}
	return false;

}

void PlayerCharacterSystem::GainEXP(ui16 gainedXP)
{
	CurrentXP += gainedXP;
	while (CheckIfLeveled()) {};
}

void PlayerCharacterSystem::ApplyBuff(Buff buff)
{
	AddNewBuff(buff);
}
