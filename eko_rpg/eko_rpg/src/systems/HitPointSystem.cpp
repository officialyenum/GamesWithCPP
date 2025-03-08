#include "HitPointSystem.h"


HitPointSystem::HitPointSystem() : CurrentHP{ 1 }, MaxHP{ 1 }, ShieldHP{ 1 }
{
}

HitPointSystem::HitPointSystem(HpType cHP, HpType mHP)
{
	SetMaxHP(mHP);
	Heal(cHP);
}

HitPointSystem::~HitPointSystem()
{
}


HpType HitPointSystem::DamageShield(HpType damage)
{
	if (ShieldHP == 0)
	{
		return damage;
	}
	if (damage > ShieldHP)
	{
		HpType damageLeft = damage - ShieldHP;
		ShieldHP = 0;
		return damageLeft;
	}
	ShieldHP -= damage;
	return 0;
}



bool HitPointSystem::SetMaxHP(HpType newMaxHP)
{
	if (newMaxHP < 1)
		return false;
	MaxHP = newMaxHP;
	if (CurrentHP > MaxHP)
		CurrentHP = MaxHP;
	return true;
}

void HitPointSystem::TakeDamage(HpType damage)
{
	HpType damageLeft = DamageShield(damage);
	if (damageLeft > CurrentHP)
	{	
		CurrentHP = 0;
		return;
	}
	CurrentHP -= damageLeft;
}

void HitPointSystem::Heal(HpType amount)
{
	if (amount + CurrentHP > MaxHP)
	{
		CurrentHP = MaxHP;
		return;
	}
	CurrentHP += amount;
}
