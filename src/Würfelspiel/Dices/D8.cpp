//
// Created by Josi on 29.02.2024.
//

#include "D8.h"

namespace Dice {
    Dice::BaseDice* D8::createComputerDice() {
        return new Dice::D8(Vector2{static_cast<float>(GetScreenWidth() * 1 / 2),
                                static_cast<float>(GetScreenHeight() * 1 / 3)});
    }
} // Dice