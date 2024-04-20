#ifndef FOOD_H
#define FOOD_H

#include "raylib.h"

class Food {
public:
    Vector2 position{};   // Stores the top-left corner position of the food texture in pixels
    Texture2D texture{};

    Food();

    ~Food();

    void Draw() const;

    Vector2 GenerateRandomPos();
};

#endif //FOOD_H
