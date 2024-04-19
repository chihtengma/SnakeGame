#include "../include/Snake.h"
#include "../include/Config.h"

Snake::Snake() {
    // Initialize the snake with a length of 3 segments
    body.push_back({16, 19});
    body.push_back({15, 19});
    body.push_back({14, 19});

    // Initial direction is to the right
    direction = {1, 0};

    lastUpdateTime = 0;
}

Snake::~Snake() = default;

void Snake::Draw() {
    for (auto &i: body) {
        int x = static_cast<int>(i.x);
        int y = static_cast<int>(i.y);

        Rectangle segment = Rectangle{static_cast<float>(x * cellSize), static_cast<float>(y * cellSize), static_cast<float>(cellSize),
                                      static_cast<float>(cellSize)};
        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
}

// Snake moving function
void Snake::Update() {
    // Reference to the head's position
    Vector2 newHead = body.front();

    // Modify the head's position based on the direction
    newHead.x += direction.x;
    newHead.y += direction.y;

    // Insert the new head at the front of the deque
    body.push_front(newHead);

    // Remove the tail segment
    body.pop_back();
}

// Function that change the snake's direction based on the input
void Snake::ChangeDirection(Vector2 newDirection) {
    // Checks to prevent the snake from reversing into itself
    if (body.size() > 1 && body[1].x  == body[0].x + newDirection.x && body[1].y == body[0].y + newDirection.y) {
        // This new direction will make the snake reverse into itself
        return;
    }
    direction = newDirection;
}

// Function that slows down the moving speed of the snake
// * double interval: change the value based on the FPS of the game
bool Snake::EventTriggered(double interval) {
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}