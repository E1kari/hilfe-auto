//
// Created by Josi on 29.02.2024.
//

#include "D6.h"

namespace Dice {
    Dice::BaseDice* D6::createComputerDice() {
        return new Dice::D6(Vector2{static_cast<float>(GetScreenWidth() * 1 / 2),
                                static_cast<float>(GetScreenHeight() * 1 / 3)});
    }
} // Dice