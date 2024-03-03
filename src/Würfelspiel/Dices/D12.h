//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_D12_H
#define RAYLIBSTARTER_D12_H

#include "BaseDice.h"

namespace Dice {

    class D12 : public Dice::BaseDice {

    public:
        D12(Vector2 _position) : Dice::BaseDice(12, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, "assets/graphics/testimage.png", 100,
                                                _position, "D12") {};

        Dice::BaseDice* createComputerDice() override;
    };

} // Dice

#endif //RAYLIBSTARTER_D12_H
