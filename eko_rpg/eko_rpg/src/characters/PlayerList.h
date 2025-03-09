#pragma once
#include "../systems/PlayerCharacterSystem.h"
#include "../utilities/CustomMacros.h"

class Agbero : public PlayerCharacterSystem {
public: 
    static const ui16 BaseHp = (ui16)14;
    static const ui16 BaseMp = (ui16)14;
    static const ui16 BaseStr = (ui16)3; 
    static const ui16 BaseInt = (ui16)3; 
    static const ui16 BaseAgi = (ui16)2; 
    static const ui16 BaseArm = (ui16)0; 
    static const ui16 BaseRes = (ui16)0; 
    Agbero() : PlayerCharacterSystem() {
        MP = std::make_unique<PointWellSystem>(BaseMp, BaseMp);
        PCCONSTRUCT
        Abilities.emplace_back("bottle throw", 1u, 3u, EAbilityTarget::ENEMY, 2u, EAbilityScalar::INT);
    }
    std::string GetClassName() { return std::string("Agbero"); }
private: 
    void LevelUp() override {
        PCLEVELUP
        if (CurrentLevel == 2)
        {
            Abilities.emplace_back("heal", 4u, 5u, EAbilityTarget::ALLY, 2u, EAbilityScalar::INT);
        }
    }
};

class ChiefPriest : public PlayerCharacterSystem {
public: 
    static const ui16 BaseHp = (ui16)10;
    static const ui16 BaseMp = (ui16)14;
    static const ui16 BaseStr = (ui16)1;
    static const ui16 BaseInt = (ui16)9;
    static const ui16 BaseAgi = (ui16)3;
    static const ui16 BaseArm = (ui16)0;
    static const ui16 BaseRes = (ui16)0;
    ChiefPriest() : PlayerCharacterSystem() {
        MP = std::make_unique<PointWellSystem>(BaseMp, BaseMp);
        PCCONSTRUCT
        Abilities.emplace_back("ThunderBolt", 2u, 1u, EAbilityTarget::ENEMY, 4u, EAbilityScalar::INT);
    }
        std::string GetClassName() { return std::string("ChiefPriest"); }
private:
    void LevelUp() override {
        PCLEVELUP
        if (CurrentLevel == 2)
        {
            Abilities.emplace_back("FireBolt", 3u, 1u, EAbilityTarget::ENEMY, 6u, EAbilityScalar::INT);
            MP->SetMax(1u + MP->GetMax());
            MP->Increase(1u);
            IncreaseStats(0, 1, 0);
        }
    }
};

class Efcc : public PlayerCharacterSystem {
public:
    static const ui16 BaseHp = (ui16)14;
    static const ui16 BaseMp = (ui16)10;
    static const ui16 BaseStr = (ui16)3;
    static const ui16 BaseInt = (ui16)3;
    static const ui16 BaseAgi = (ui16)2;
    static const ui16 BaseArm = (ui16)0;
    static const ui16 BaseRes = (ui16)0;
    Efcc() : PlayerCharacterSystem() {
        PCCONSTRUCT
    }
        std::string GetClassName() { return std::string("Efcc"); }
private:
    void LevelUp() override {
        PCLEVELUP
    }
};

class Politician : public PlayerCharacterSystem {
public:
    static const ui16 BaseHp = (ui16)14;
    static const ui16 BaseMp = (ui16)10;
    static const ui16 BaseStr = (ui16)3;
    static const ui16 BaseInt = (ui16)3;
    static const ui16 BaseAgi = (ui16)2;
    static const ui16 BaseArm = (ui16)0;
    static const ui16 BaseRes = (ui16)0;
    Politician() : PlayerCharacterSystem() {
        PCCONSTRUCT
    }
        std::string GetClassName() { return std::string("Politician"); }
private:
    void LevelUp() override {
        PCLEVELUP
    }
};


