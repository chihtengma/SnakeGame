#include "raylib.h"

#include "../include/Game.h"
#include "../include/Config.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(2 * Config::offSet + Config::cellSize * Config::cellCount, 2 * Config::offSet + Config::cellSize * Config::cellCount,
               "Retro Snake Game");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Game game;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        game.Draw();
        game.HandleUserInput(game);

        if (game.getCurrentState() != GameState::GameOver) {
            game.Update();
        }
    }
    return 0;
}