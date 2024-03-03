//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_D8_H
#define RAYLIBSTARTER_D8_H

#include "BaseDice.h"

namespace Dice {

    class D8 : public Dice::BaseDice {

    public:
        D8(Vector2 _position) : Dice::BaseDice(8, {1, 2, 3, 4, 5, 6, 7, 8}, "assets/graphics/testimage.png", 100,
                                               _position, "D8") {};
    Dice::BaseDice* createComputerDice() override;
    };

} // Dice

#endif //RAYLIBSTARTER_D8_H
