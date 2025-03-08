#pragma once

#include "../../src/types/CustomTypes.h"

class PointWellSystem
{
private:
	ui16 Current;
	ui16 Max;

public:
	PointWellSystem();
	PointWellSystem(ui16 cPW, ui16 mPW);
	~PointWellSystem();
	bool SetMax(ui16 newMax);
	void Reduce(ui16 damage);
	void Increase(ui16 amount);

	ui16 GetMax() { return Max;  }
	ui16 GetCurrent() { return Current;  }
};
