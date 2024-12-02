#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Enemy.h"
#include "Prop.h"
#include <string>

using namespace std;

int main()
{
    const int windowWidth{768};
    const int windowHeight{768};
    InitWindow(windowWidth, windowHeight, "Yenum's Clashy");
    Texture2D sandBoxMap = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.f, 0.f};
    float mapScale{4.f};

    Character Knight{windowWidth, windowHeight};
    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

    Enemy enemies[]{
        Enemy{ Vector2{}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")},
        Enemy{ Vector2{100.f, 100.f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")},
        Enemy{ Vector2{400.f, 100.f}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("characters/goblin_run_spritesheet.png")},
        Enemy{ Vector2{5000.f, 700.f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")},
        Enemy{ Vector2{5000.f, 5000.f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")},
        Enemy{ Vector2{800.f, 5000.f}, LoadTexture("characters/slime_idle_spritesheet.png"), LoadTexture("characters/slime_run_spritesheet.png")}
    };

    for (auto &enemy : enemies)
    {
        enemy.setTarget(&Knight);
    }

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // draw the map;
        mapPos = Vector2Scale(Knight.GetWorldPos(), -1.f);
        DrawTextureEx(sandBoxMap, mapPos, 0.0, mapScale, WHITE);

        // update Knight
        Knight.tick(GetFrameTime());
        
        // Draw props
        for (auto &renderProp : props)
        {
            renderProp.Render(Knight.GetWorldPos());
        }

        if (Knight.GetWorldPos().x < 0.f ||
            Knight.GetWorldPos().y < 0.f ||
            Knight.GetWorldPos().x + windowWidth > sandBoxMap.width * mapScale ||
            Knight.GetWorldPos().y + windowHeight > sandBoxMap.height * mapScale)
        {
            /* Check Map Bounds */
            Knight.UndoMovement();
        }

        /* Check Collission with Props */
        for (auto collissionprop : props)
        {
            if (CheckCollisionRecs(Knight.getCollissionRec(), collissionprop.getCollissionRec(Knight.GetWorldPos())))
            {
                /* Check Collission with Props */
                Knight.UndoMovement();
            }
        }

        if (!Knight.getAlive())
        {
            
            DrawText("Game Over! ", windowWidth/3, windowHeight/3, 48, RED);
            
            EndDrawing();
            continue;
        }else{
            string KnightsHealth = "Health: ";
            KnightsHealth.append(to_string(Knight.GetHealth()), 0, 5);
            // C-Style
            DrawText(KnightsHealth.c_str(), 55, 45, 40, RED);
            // Render Knight Health Raylib Style
            // DrawText(TextFormat("Health : %02i", static_cast<int>(Knight.GetHealth())), 10, 10, 24, RED);
        }
        

        // Render Enemy
        for (auto &renderEnemy : enemies)
        {
            renderEnemy.tick(GetFrameTime());
        }

        
        // Check Weapon Collission With Enemy
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            /* code */
            for (auto &colEnemy : enemies)
            {
                if (CheckCollisionRecs(colEnemy.getCollissionRec(), Knight.GetWeaponCollissionRec()))
                {
                    /* Check Collission with Weapon */
                    colEnemy.setAlive(false);
                }
            }
        }
        
        
        EndDrawing();
    }
    UnloadTexture(sandBoxMap);
    CloseWindow();
}