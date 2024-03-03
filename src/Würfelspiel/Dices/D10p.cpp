//
// Created by Josi on 29.02.2024.
//

#include "D10p.h"

namespace Dice {

    Dice::BaseDice* D10p::createComputerDice() {
        return new Dice::D10p(Vector2{static_cast<float>(GetScreenWidth() * 1 / 2),
                                  static_cast<float>(GetScreenHeight() * 1 / 3)});

    }
} // Dice