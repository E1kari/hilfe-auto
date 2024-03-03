//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_D10_H
#define RAYLIBSTARTER_D10_H

#include "BaseDice.h"

namespace Dice {

    class D10 : public Dice::BaseDice {

    public:
        D10(Vector2 _position) : Dice::BaseDice(10, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, "assets/graphics/testimage.png", 100,
                                                _position, "D10") {};

        Dice::BaseDice* createComputerDice() override;
    };

} // Dice

#endif //RAYLIBSTARTER_D10_H
