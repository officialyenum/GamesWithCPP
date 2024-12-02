#include "raylib.h"
#include "BaseCharacter.h"
#include "Character.h"

class Enemy : public BaseCharacter
{
public:
    Enemy(Vector2 pos, Texture2D idleTex, Texture2D runTex);
    void setTarget(Character* Knight) { target = Knight; }
    virtual Vector2 GetScreenPos() override;
    virtual void tick(float deltaTime) override;
private:
    Character* target;
    float damagePerSec{10.f};
    float radius{30.f};
};
