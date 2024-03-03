//
// Created by Josi on 29.02.2024.
//

#include "D12.h"

namespace Dice {

    Dice::BaseDice* D12::createComputerDice() {
        return new Dice::D12(Vector2{static_cast<float>(GetScreenWidth() * 1 / 2),
                                  static_cast<float>(GetScreenHeight() * 1 / 3)});
    }
} // Dice