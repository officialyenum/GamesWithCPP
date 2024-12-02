#include "prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex)
{
    worldPos = pos;
    texture = tex;
}

void Prop::Render(Vector2 KnightPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, KnightPos)};
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}

Rectangle Prop::getCollissionRec(Vector2 KnightPos)
{
    Vector2 screenPos{Vector2Subtract(worldPos, KnightPos)};
    return Rectangle{
        screenPos.x,
        screenPos.y,
        texture.width * scale,
        texture.height * scale};
}