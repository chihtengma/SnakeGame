#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"

class Game {
public:


    Game();

    ~Game();

    void Draw();

    void Update();

    Vector2 GenerateValidFoodPosition();

    // Accessor
    Snake &GetSnake() { return snake; };

    Food &GetFood() { return food; };

private:
    Snake snake;
    Food food;
};

#endif //GAME_H
