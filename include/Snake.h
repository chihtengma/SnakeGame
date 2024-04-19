#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "raylib.h"

class Snake {
public:
    std::deque<Vector2> body;
    Vector2 direction;

    double lastUpdateTime;

    Snake();

    ~Snake();

    void Draw();

    void Update();

    bool EventTriggered(double);

    void ChangeDirection(Vector2);
};

#endif //SNAKE_H
