#include "PointWellSystem.h"


PointWellSystem::PointWellSystem() : Current{ 1 }, Max{ 1 }
{
}

PointWellSystem::PointWellSystem(ui16 cPW, ui16 mPW)
{
	Current = cPW;
	Max = mPW;
	if (Current > Max)
		Current = Max;
}

PointWellSystem::~PointWellSystem()
{
}



bool PointWellSystem::SetMax(ui16 newMax)
{
	if (newMax < 1)
		return false;
	Max = newMax;
	if (Current > Max)
		Current = Max;
	return true;
}


void PointWellSystem::Reduce(ui16 damage)
{
	if (damage > Current)
	{	
		Current = 0;
		return;
	}
	Current -= damage;
}

void PointWellSystem::Increase(ui16 amount)
{
	if (amount + Current > Max)
	{
		Current = Max;
		return;
	}
	Current += amount;
}
