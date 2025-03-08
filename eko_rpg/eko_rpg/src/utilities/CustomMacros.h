#pragma once

#define PCCONSTRUCT : PlayerCharacterSystem() { \
HP->SetMax(BaseHp);\
HP->Increase(BaseHp);\
IncreaseStats(BaseStr, BaseInt, BaseAgi, BaseArm, BaseRes);\
}

#define PCLEVELUP void LevelUp() override {\
HP->SetMax((ui16)((BaseHp / 2.f) + HP->GetMax()));\
HP->Increase((ui16)((BaseHp / 2.f)));\
IncreaseStats((ui16)((BaseStr + 1u) / 2.f), (ui16)((BaseInt + 1u) / 2.f), (ui16)((BaseAgi + 1u) / 2.f), (ui16)((BaseArm + 1u) / 2.f), (ui16)((BaseRes + 1u) / 2.f));\
}

#define CHARACTERCLASS(classname, basehp, basestr, baseint, baseagi, basearm, baseres)\
class classname : public PlayerCharacterSystem {\
public:\
	static const ui16 BaseHp = (ui16)basehp;\
	static const ui16 BaseStr = (ui16)basestr;\
	static const ui16 BaseInt = (ui16)baseint;\
	static const ui16 BaseAgi = (ui16)baseagi;\
	static const ui16 BaseArm = (ui16)basearm;\
	static const ui16 BaseRes = (ui16)baseres;\
	classname()PCCONSTRUCT\
	std::string GetClassName() { return std::string(#classname); }\
private:\
	PCLEVELUP\
};
