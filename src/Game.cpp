#include "../include/Game.h"

#include <iostream>

Game::Game() : snake(), food() {
    food.position = GenerateValidFoodPosition();
}

Game::~Game() = default;

void Game::Draw() {
    food.Draw();
    snake.Draw();
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

void Game::Update() {
    snake.Update(); // Update the snake's position

    // Check if the snake eats the food
    if (snake.body[0].x == food.position.x && snake.body[0].y == food.position.y) {
        // Snake eats the food

        std::cout << "Food eaten at: (" << food.position.x << ", " << food.position.y << ")" << std::endl;


        // 1. Grow the snake by adding a new segment to its tail
        Vector2 newSegment = snake.body.back(); // copy the last segment;
        snake.body.push_back(newSegment);

        // 2. Generate a new position for the food
        food.position = GenerateValidFoodPosition();

        // TBD.... game score or level
    }

    // TBD.... collision detection, game over detection.
}
