#ifndef CONFIG_H
#define CONFIG_H

namespace Config {
    constexpr int cellSize = 30;
    constexpr int cellCount = 30;

    constexpr Color green = {173, 204, 96, 255};
    constexpr Color darkGreen = {43, 51, 24, 255};
}


extern Color green;
extern Color darkGreen;

#endif //CONFIG_H
