#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"

enum class GameState {
    Playing,
    GameOver
};

class Game {
public:
    Game();

    ~Game();

    void Draw();

    void Update(Game &);

    void ResetGame();

    Vector2 GenerateValidFoodPosition();

    void CheckCollisionWithFood();

    void CheckCollisionWithBoundaries();

    void HandleUserInput(Game &);

    // Accessor
    Snake &GetSnake() { return snake; };

    Food &GetFood() { return food; };

    GameState getCurrentState() { return currentState; };

private:
    Snake snake;
    Food food;
    GameState currentState = GameState::Playing;
};

#endif //GAME_H
