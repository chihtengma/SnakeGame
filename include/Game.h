#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"

class Game {
public:
    Snake snake;
    Food food;

    Game();

    ~Game();

    void Draw();

    void Update();

    Vector2 GenerateValidFoodPosition();
};

#endif //GAME_H
