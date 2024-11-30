#include "raylib.h"

struct AnimData
{
    Rectangle Rec;
    Vector2 Pos;
    int frame;
    float updateTime;
    float runningTime;
};

bool isOnGround(AnimData data, int windowHeight)
{
   return data.Pos.y >= windowHeight - data.Rec.height;
}

AnimData updateAnimData(AnimData data, float deltaTime, int maxFrame)
{
    // update scarfy running time
    data.runningTime += deltaTime;
    if (data.runningTime >= data.updateTime)
    {
        data.runningTime = 0;
        // update scarfy animation frame;
        data.Rec.x = data.frame * data.Rec.width;
        data.frame++;
        if (data.frame > maxFrame)
        {
            data.frame = 0;
        }
    }
    return data;
}

int main()
{
    // window dimensions
    int windowDimensions[2];
    windowDimensions[0] = 800;
    windowDimensions[1] = 600;

    InitWindow(windowDimensions[0], windowDimensions[1], "Dapper Dasher!");

    // acceleration due to gravity (pixels/s)/s
    const int gravity{1000};

    // Nebula Setup
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    int sizeOfNebulae{3};
    AnimData nebulaes[sizeOfNebulae]{};
    for (int i = 0; i < sizeOfNebulae; i++)
    {
        nebulaes[i].Rec.x = 0.0;
        nebulaes[i].Rec.y = 0.0;
        nebulaes[i].Rec.width = nebula.width/8.0;
        nebulaes[i].Rec.height = nebula.height/8.0;
        nebulaes[i].Pos.x = windowDimensions[0] + i * 300;
        nebulaes[i].Pos.y = windowDimensions[1] - nebula.height/8.0;
        nebulaes[i].frame = 0.0;
        nebulaes[i].updateTime = 1.0/16.0;
        nebulaes[i].runningTime = 0.0;
        
    }
    int nebVel{-200};
    float finishLine{ nebulaes[sizeOfNebulae - 1].Pos.x };

    // Scarfy Character Setup
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    AnimData scarfyData{ 
        {0.0,0.0, scarfy.width /6,scarfy.height }, // Rectangle rec
        {windowDimensions[0]/2 - scarfy.width/6, windowDimensions[1] - scarfy.height}, //vector2 pos
        0, // int frame
        1.0/12.0, // float update Time
        0, // float runningTime
    };

    int velocity{0};
    // is scarfy in the air
    bool isInAir{false};
    // jump velocity (pixels / second)
    const int jumpVelocity{-600};

    Texture2D background = LoadTexture("textures/far-buildings.png");
    float bgX{};
    const float bgScale{ 3.5 };
    Texture2D midground = LoadTexture("textures/back-buildings.png");
    float mgX{};
    Texture2D foreground = LoadTexture("textures/foreground.png");
    float fgX{};

    bool collission{ false };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        
        // delta time (time since last frame)
        float dT{ GetFrameTime() };
        
        
        BeginDrawing();
        ClearBackground(GRAY);

        // Draw Background
        bgX -= 20 * dT;
        if(bgX <= -background.width * bgScale)
        {
            bgX = 0.0;
        }
        Vector2 bg1Pos{ bgX, 0.0 };
        DrawTextureEx(background, bg1Pos, 0.0, bgScale, WHITE);
        Vector2 bg2Pos{ bgX + background.width * bgScale, 0.0 };
        DrawTextureEx(background, bg2Pos, 0.0, bgScale, WHITE);



        // Draw Midground
        mgX -= 40 * dT;
        if(mgX <= -midground.width * bgScale)
        {
            mgX = 0.0;
        }
        
        Vector2 mg1Pos{ mgX, 0.0 };
        DrawTextureEx(midground, mg1Pos, 0.0, bgScale, WHITE);
        Vector2 mg2Pos{ mgX + midground.width * bgScale, 0.0 };
        DrawTextureEx(midground, mg2Pos, 0.0, bgScale, WHITE);

        
        // Draw Foreground
        fgX -= 80 * dT;
        if(fgX <= -foreground.width * bgScale)
        {
            fgX = 0.0;
        }

        Vector2 fg1Pos{ fgX, 0.0 };
        DrawTextureEx(foreground, fg1Pos, 0.0, bgScale, WHITE);
        Vector2 fg2Pos{ fgX + foreground.width * bgScale, 0.0 };
        DrawTextureEx(foreground, fg2Pos, 0.0, bgScale, WHITE);


        // perform ground check
        
        if (isOnGround(scarfyData, windowDimensions[1]))
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity * dT;
            isInAir = true;
        }
        if (!isInAir)
        {
            // update scarfy running time
            scarfyData = updateAnimData(scarfyData, dT, 5);
        }
        
        for (int i = 0; i < sizeOfNebulae; i++)
        {
            // update nebula running time
            nebulaes[i] = updateAnimData(nebulaes[i], dT, 7);
        }
        

        
        // Jump Check
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {

            velocity += jumpVelocity; 
        }
        for (int i = 0; i < sizeOfNebulae; i++)
        {
            // update nebula position
            nebulaes[i].Pos.x += nebVel * dT;
        }

        // update finish line
        finishLine += nebVel * dT;

        
        
        
        // update scarfy position
        scarfyData.Pos.y += velocity * dT;

        for (AnimData nebula : nebulaes)
        {
            float pad{40};
            Rectangle nebRec{
                nebula.Pos.x + pad,
                nebula.Pos.y + pad,
                nebula.Rec.width - 2 * pad,
                nebula.Rec.height - 2 * pad,
            };

            Rectangle scarfyRecTemp{
                scarfyData.Pos.x,
                scarfyData.Pos.y,
                scarfyData.Rec.width,
                scarfyData.Rec.height,
            };

            if (CheckCollisionRecs(nebRec, scarfyRecTemp))
            {
                collission = true;
            }
            
        }
         
        if (collission)
        {
            // loose the game 
            DrawText("Game Over", windowDimensions[0]/3, windowDimensions[1]/2, 48, RED);
        }
        else
        {
            if (finishLine <= 0)
            {
                DrawText("You Win !!!", windowDimensions[0]/3, windowDimensions[1]/2, 48, GREEN);
            }
            else{
                for (int i = 0; i < sizeOfNebulae; i++)
                {
                    // update draw
                    DrawTextureRec(nebula,nebulaes[i].Rec,nebulaes[i].Pos,WHITE);
                }
                // draw scarfy
                DrawTextureRec(scarfy,scarfyData.Rec,scarfyData.Pos,WHITE);
            }
            
         }
         
        EndDrawing();
    }
    UnloadTexture(nebula);
    UnloadTexture(scarfy);
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
    CloseWindow();

    

    
}