#include "../include/Game.h"
#include "../include/Config.h"

Game::Game() : soundPlayed(false), snake(), food() {
    InitAudioDevice();
    eatSound = LoadSound("../assets/Sounds/eat.mp3");
    wallSound = LoadSound("../assets/Sounds/wall.mp3");
    food.position = GenerateValidFoodPosition();
}

Game::~Game() {
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(Config::green);
    DrawRectangleLinesEx(
            Rectangle{(float) Config::offSet - 5, (float) Config::offSet - 5, (float) Config::cellSize * Config::cellCount + 10,
                      (float) Config::cellSize * Config::cellCount + 10}, 5, Config::darkGreen);
    DrawText("Retro Snake", Config::offSet - 5, 30, 40, Config::darkGreen);
    std::string scoreText = "Score: " + std::to_string(GetScore());
    DrawText(scoreText.c_str(), Config::offSet + 720, 30, 40, Config::darkGreen);

    if (currentState == GameState::Playing) {
        snake.Draw();
        food.Draw();
    } else if (currentState == GameState::GameOver) {
        DrawText("Game Over!", 420, 450, 30, RED);
        DrawText("Press [R] to Replay or [Q] to Quit", 260, 500, 30, DARKGRAY);
    }

    EndDrawing();
}

// This function make sure that new food won't overlap with the snake
Vector2 Game::GenerateValidFoodPosition() {
    Vector2 newPosition;
    bool isValid;

    do {
        newPosition = food.GenerateRandomPos();
        isValid = true;

        for (const auto &segment: snake.body) {
            // Check if the position overlaps with the snake, generate a new one if it does
            if (segment.x == newPosition.x && segment.y == newPosition.y) {
                isValid = false;
                break;
            }
        }
    } while (!isValid);
    return newPosition;
}

// This function checks if the snake eats the food
void Game::CheckCollisionWithFood() {
    // Check if the snake eats the food
    if (snake.body[0].x == food.position.x && snake.body[0].y == food.position.y) {
        // Snake eats the food

        // 1. Grow the snake by adding a new segment to its tail
        Vector2 newSegment = snake.body.back(); // copy the last segment;
        snake.body.push_back(newSegment);
        IncrementScore();
        PlaySound(eatSound);

        // 2. Generate a new position for the food
        food.position = GenerateValidFoodPosition();
    }
}

// Check if the snake hits the boundaries
bool Game::CheckCollisionWithBoundaries() {
    Vector2 head = snake.body.front();

    if (head.x < 0 || head.x >= Config::cellCount ||
        head.y < 0 || head.y >= Config::cellCount) {
        currentState = GameState::GameOver;
        return true;
    }
    return false;
}

// Check if the snake hits the tail
bool Game::CheckCollisionWithTail() {
    const Vector2 &head = snake.body.front();

    for (auto it = snake.body.begin() + 1; it != snake.body.end(); ++it) {
        if (head.x == it->x && head.y == it->y) {
            currentState = GameState::GameOver;
            return true;
        }
    }
    return false;
}

// Handling snake's direction based on user input
void Game::HandleUserInput(Game &game) {
    if (game.currentState == GameState::GameOver) {
        if (IsKeyPressed(KEY_R)) {
            ResetGame();  // Reinitialize the game
        } else if (IsKeyPressed(KEY_Q)) {
            CloseWindow();
        }
    } else {
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1)
            game.snake.ChangeDirection({1, 0});
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1)
            game.snake.ChangeDirection({-1, 0});
        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1)
            game.snake.ChangeDirection({0, -1});
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1)
            game.snake.ChangeDirection({0, 1});
    }
}

void Game::ResetGame() {
    snake = Snake();
    food.position = food.GenerateRandomPos();
    currentState = GameState::Playing;
    ResetScore();
    soundPlayed = false;
}

void Game::ResetScore() {
    score = 0;
}

void Game::Update() {
    // Update
    if (GetSnake().EventTriggered(0.2)) {
        snake.Update(); // Update the snake's position
    }

    if (CheckCollisionWithBoundaries() || CheckCollisionWithTail()) {
        if (!soundPlayed) {
            PlaySound(wallSound);
            soundPlayed = true;
        }
        currentState = GameState::GameOver;
        return; // Ensure no further processing happens after this
    }


    CheckCollisionWithFood();
}
