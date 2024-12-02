#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idleTex, Texture2D runTex)
{
    worldPos = pos;
    texture = idleTex;
    idle = idleTex;
    run = runTex;
    width = texture.width / maxFrames;
    height = texture.height;
    speed = 3.5f;
}

Vector2 Enemy::GetScreenPos()
{
    return Vector2Subtract(worldPos, target->GetWorldPos());
}

void Enemy::tick(float deltaTime)
{
    if (!getAlive())
        return;
    velocity = Vector2Subtract(target->GetScreenPos(), GetScreenPos());
    if (Vector2Length(velocity) < radius) velocity = {};
    
    BaseCharacter::tick(deltaTime);
    if (CheckCollisionRecs(getCollissionRec(), target->getCollissionRec()))
    {
        /* Check Collission with Weapon */
        target->TakeDamage(damagePerSec * deltaTime);
    }
}