#include "../include/Food.h"
#include "../include/Config.h"

Color darkGreen = {43, 51, 24, 255};

Food::Food() {
    Image image = LoadImage("../assets/Graphics/food.png"); // Path to the food image
    texture = LoadTextureFromImage(image);
    UnloadImage(image); //  Free the memory once the texture is created
    position = GenerateRandomPos();
}

Food::~Food() {
    UnloadTexture(texture); // Ensure resources are cleaned up properly
}

void Food::Draw() {
    DrawTexture(texture, static_cast<int>(position.x * static_cast<float>(cellSize)),
                static_cast<int>(position.y * static_cast<float>(cellSize)), darkGreen);
}

Vector2 Food::GenerateRandomPos() {
    int gridX = GetRandomValue(0, cellCount - 1);   // Get random grid cell x-coordinate
    int gridY = GetRandomValue(0, cellCount - 1);   // Get random grid cell y-coordinate

    return Vector2{
            static_cast<float>(gridX),   // Convert grid cell coordinate to pixel coordinate
            static_cast<float>(gridY)    // Convert grid cell coordinate to pixel coordinate
    };
}