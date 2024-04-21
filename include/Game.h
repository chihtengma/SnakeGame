#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <thread>

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

    void Update();

    void ResetGame();

    Vector2 GenerateValidFoodPosition();

    void CheckCollisionWithFood();

    bool CheckCollisionWithBoundaries();

    bool CheckCollisionWithTail();

    void HandleUserInput(Game &);

    // Accessor
    Snake &GetSnake() { return snake; };

    Food &GetFood() { return food; };

    int &GetScore() { return score; };

    int IncrementScore() { return ++score; };

    void ResetScore();

    GameState getCurrentState() { return currentState; };

private:
    Snake snake;
    Food food;
    Sound eatSound;
    Sound wallSound;
    bool soundPlayed;
    GameState currentState = GameState::Playing;
    int score = 0;
};

#endif //GAME_H
