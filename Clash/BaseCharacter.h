
#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include "raylib.h"

class BaseCharacter
{
public:
    BaseCharacter();
    Vector2 GetWorldPos() { return worldPos; }
    void UndoMovement();
    Rectangle getCollissionRec();
    virtual void tick(float deltaTime);
    virtual Vector2 GetScreenPos() = 0;
    bool getAlive() { return alive; }
    void setAlive(bool isAlive) { alive = isAlive; }
protected:
    Texture2D texture{LoadTexture("characters/Knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/Knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/Knight_run_spritesheet.png")};
    Vector2 worldPos;
    Vector2 worldPosLastFrame;
    float width{};
    float height{};

    float scale{4.0f};
    // player facing direction 1 facing right : -1 facing left;
    float rightLeft{1.f};
    // animation variables
    float runninngTime{};
    int frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    Vector2 velocity{};

private:
    bool alive{true};
};

#endif