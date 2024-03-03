//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_D20_H
#define RAYLIBSTARTER_D20_H

#include "BaseDice.h"

namespace Dice {

    class D20 : public Dice::BaseDice {

    public:
        D20(Vector2 _position) : Dice::BaseDice(20, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
                                                "assets/graphics/testimage.png", 100,
                                                _position, "D20") {};

        BaseDice * createComputerDice() override;
    };

} // Dice

#endif //RAYLIBSTARTER_D20_H
