#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    // update animation
    runninngTime += deltaTime;
    if (runninngTime >= updateTime)
    {
        frame++;
        runninngTime = 0.f;
        if (frame >= maxFrames)
            frame = 0.f;
    }

    if (Vector2Length(velocity) != 0.0)
    {
        // normalize example : 1.414 becomes 1.0;
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(velocity), speed));
        rightLeft = velocity.x < 0.f ? -1.f : 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    velocity = {};

    // draw the character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{GetScreenPos().x, GetScreenPos().y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}


void BaseCharacter::UndoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle BaseCharacter::getCollissionRec()
{
    return Rectangle{
        GetScreenPos().x,
        GetScreenPos().y,
        width * scale,
        height * scale};
}
