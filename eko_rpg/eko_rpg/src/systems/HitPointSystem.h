#pragma once

#include "../../src/types/CustomTypes.h"

class HitPointSystem
{
private:
	HpType ShieldHP;
	HpType CurrentHP;
	HpType MaxHP;

	HpType DamageShield(HpType damage);
public:
	HitPointSystem();
	HitPointSystem(HpType cHP, HpType mHP);
	~HitPointSystem();
	bool SetMaxHP(HpType newMaxHP);
	void TakeDamage(HpType damage);
	void Heal(HpType amount);

	HpType GetMaxHP() { return MaxHP;  }
	HpType GetCurrentHP() { return CurrentHP;  }
	HpType GetShieldHP() { return ShieldHP; }
};
