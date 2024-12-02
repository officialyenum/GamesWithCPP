
#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual Vector2 GetScreenPos() override;
    virtual void tick(float deltaTime) override;
    Rectangle GetWeaponCollissionRec() { return weaponCollissionRec; }
    float GetHealth() const { return health; }
    void TakeDamage(float damage);
private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponCollissionRec{};
    float health{ 100.f };
};

#endif