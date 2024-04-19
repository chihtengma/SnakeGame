#include "raylib.h"

#include "../include/Game.h"
#include "../include/Config.h"

/*
 * Colors
    - Green {173, 204, 96, 255}
    - Dark Green {43, 51, 24, 255}
 */
int cellCount = 30;
int cellSize = 30;

Color green = {173, 204, 96, 255};

// Handling snake's direction based on user input
void HandleInput(Snake &snake) {
    if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
        snake.ChangeDirection({1, 0});
    if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
        snake.ChangeDirection({-1, 0});
    if (IsKeyPressed(KEY_UP) && snake.direction.y != 1)
        snake.ChangeDirection({0, -1});
    if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
        snake.ChangeDirection({0, 1});
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake Game");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Game game = Game();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        // Update
        //----------------------------------------------------------------------------------
        if (game.snake.EventTriggered(0.2)) {
            game.Update();
        }

        // Handle snake's direction
        HandleInput(game.snake);

        // Drawing
        ClearBackground(green);
        game.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}