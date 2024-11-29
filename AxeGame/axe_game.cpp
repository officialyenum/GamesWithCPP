#include "raylib.h"

int main() 
{
    // Window dimensions
    float width{ 800 }; 
    float height{ 600 }; 
    

    InitWindow(width, height, "Axe Game");
    
    // Circle Coordinates
    int circleY{ 200 };
    int circleX{ 200 };
    int circleRadius{ 25 };
    // circle edges
    int l_circle_x{ circleX - circleRadius};
    int r_circle_x{ circleX + circleRadius};
    int u_circle_y{ circleY - circleRadius};
    int d_circle_y{ circleY + circleRadius};
    // Axe Coordinates
    int axeY{ 0 };
    int axeX{ 400 };
    int axeLength{ 50 };
    // Axe edges
    int l_axe_x{ axeX};
    int r_axe_x{ axeX + axeLength};
    int u_axe_y{ axeY};
    int d_axe_y{ axeY + axeLength};

    int direction{ 10 };

    bool collissionWithAxe = (d_axe_y >= u_circle_y) && 
        (u_axe_y <= d_circle_y) && 
        (r_axe_x >= l_circle_x) && 
        (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(RED);
        
        if (collissionWithAxe)
        {
            DrawText("GAME OVER", 350, 200, 24, WHITE);
        }
        else{
            // Game Logic Starts
            axeY += direction;
            if (axeY > height || axeY < 0)
            {
                direction = -direction;
                
            }
            
            if (IsKeyDown(KEY_D) && circleX < width)
            {
                circleX += 10;
            }
            if (IsKeyDown(KEY_A) && circleX > 0)
            {
                circleX -= 10;
            }
            if (IsKeyDown(KEY_W) && circleY > 0)
            {
                circleY -= 10;
                u_circle_y = circleY - circleRadius;
                d_circle_y = circleY + circleRadius;
            }
            if (IsKeyDown(KEY_S) && circleY < height)
            {
                circleY += 10;
            }
            
            l_circle_x = circleX - circleRadius;
            r_circle_x = circleX + circleRadius;
            u_circle_y = circleY - circleRadius;
            d_circle_y = circleY + circleRadius;
            l_axe_x = axeX;
            r_axe_x = axeX + axeLength;
            u_axe_y = axeY;
            d_axe_y = axeY + axeLength;
            // Update Collission with Axe
            collissionWithAxe = 
                (d_axe_y >= u_circle_y) && 
                (u_axe_y <= d_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_circle_x);
            DrawCircle(circleX, circleY, circleRadius, WHITE);
            DrawRectangle(axeX, axeY, axeLength, axeLength, BLUE);
            
            // Game Logic Ends
        }
        
        EndDrawing();
    }
    
}