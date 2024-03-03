//
// Created by Josi on 29.02.2024.
//

#include "D20.h"

namespace Dice {
    BaseDice* D20::createComputerDice() {
        return new Dice::D20(Vector2{static_cast<float>(GetScreenWidth() * 1 / 2),
                                static_cast<float>(GetScreenHeight() * 1 / 3)});
    }
} // Dice