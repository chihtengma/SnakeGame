#include "raylib.h"

#include "../include/Game.h"
#include "../include/Config.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(Config::cellSize * Config::cellCount, Config::cellSize * Config::cellCount, "Retro Snake Game");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Game game;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        game.Update(game);
    }
    return 0;
}