#include "raylib.h"

struct AnimData
{
    Rectangle Rec;
    Vector2 Pos;
    int frame;
    float updateTime;
    float runningTime;
};

int main()
{
    // window dimensions
    const int windowWidth{ 800 };
    const int windowHeigth{ 600 };

    InitWindow(windowWidth, windowHeigth, "Dapper Dasher!");

    // acceleration due to gravity (pixels/s)/s
    const int gravity{1000};

    // Nebula Setup
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    // Nebula Data
    AnimData nebulaData{ 
        {0.0,0.0, nebula.width/8.0, nebula.height/8.0}, 
        {windowWidth, windowHeigth - nebula.height/8.0},
        0,
        1.0/12.0,
        0,
    };
    int nebVel{-200};
    // Nebula 2 Data
    AnimData nebula2Data{ 
        {0.0,0.0, nebula.width/8.0, nebula.height/8.0}, 
        {windowWidth + 200, windowHeigth - nebula.height/8.0},
        0,
        1.0/12.0,
        0,
    };
    int neb2Vel{-200};

    // Scarfy Character Setup
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    AnimData scarfyData{ 
        {0.0,0.0,scarfy.width/6,scarfy.height}, // Rectangle rec
        {windowWidth/2 - scarfy.width/2, windowHeigth - scarfy.height}, //vector2 pos
        0, // int frame
        1.0/12.0, // float update Time
        0, // float runningTime
    };

    int velocity{0};
    // is scarfy in the air
    bool isInAir{false};
    // jump velocity (pixels / second)
    const int jumpVelocity{-600};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        
        // delta time (time since last frame)
        float dT{ GetFrameTime() };
        
        
        BeginDrawing();
        ClearBackground(GRAY);

        // perform ground check
        if (scarfyData.Pos.y >= (windowHeigth - scarfyData.Rec.height))
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
            scarfyData.runningTime += dT;
            if (scarfyData.runningTime >= scarfyData.updateTime)
            {
                // update scarfy animation frame;
                scarfyData.Rec.x = scarfyData.frame * scarfyData.Rec.width;
                scarfyData.frame++;
                if (scarfyData.frame > 5)
                {
                    scarfyData.frame = 0;
                }
                scarfyData.runningTime = 0;
            }
        }
        
        // update nebula running time
        nebulaData.runningTime += dT;
        if (nebulaData.runningTime >= nebulaData.updateTime)
        {
            // update nebula animation frame;
            nebulaData.Rec.x = nebulaData.frame * nebulaData.Rec.width;
            nebulaData.frame++;
            if (nebulaData.frame > 7)
            {
                nebulaData.frame = 0;
            }
            nebulaData.runningTime = 0;
        }

        // update nebula 2 running time
        nebula2Data.runningTime += dT;
        if (nebula2Data.runningTime >= nebula2Data.updateTime)
        {
            // update nebula animation frame;
            nebula2Data.Rec.x = nebula2Data.frame * nebula2Data.Rec.width;
            nebula2Data.frame++;
            if (nebula2Data.frame > 7)
            {
                nebula2Data.frame = 0;
            }
            nebula2Data.runningTime = 0;
        }
        
        // Jump Check
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {

            velocity += jumpVelocity; 
        }
        // update nebula position
        nebulaData.Pos.x += nebVel * dT;
        // update nebula position
        nebula2Data.Pos.x += nebVel * dT;
        // update scarfy position
        scarfyData.Pos.y += velocity * dT;

        
        //draw nebula
        DrawTextureRec(nebula,nebulaData.Rec,nebulaData.Pos,WHITE);
        //draw nebula 
        DrawTextureRec(nebula,nebula2Data.Rec,nebula2Data.Pos,WHITE);
        // draw scarfy
        DrawTextureRec(scarfy,scarfyData.Rec,scarfyData.Pos,WHITE);
        EndDrawing();
    }
    UnloadTexture(nebula);
    UnloadTexture(scarfy);
    CloseWindow();

    

    
}