//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_D6_H
#define RAYLIBSTARTER_D6_H

#include "BaseDice.h"

namespace Dice {

    class D6 : public Dice::BaseDice {

    public:
        D6(Vector2 _position) : Dice::BaseDice(6, {1, 2, 3, 4, 5, 6}, "assets/graphics/testimage.png", 100,
                                               _position, "D6") {};
    Dice::BaseDice* createComputerDice() override;
    };

} // Dice

#endif //RAYLIBSTARTER_D6_H
