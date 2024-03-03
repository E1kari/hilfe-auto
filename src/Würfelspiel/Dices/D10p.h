//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_D10P_H
#define RAYLIBSTARTER_D10P_H

#include "BaseDice.h"

namespace Dice {

    class D10p : public Dice::BaseDice {

    public:
        D10p(Vector2 _position) : Dice::BaseDice(10, {00, 10, 20, 30, 40, 50, 60, 70, 80, 90}, "assets/graphics/testimage.png",
        100, _position, "D10p") {};

        Dice::BaseDice* createComputerDice() override;
    };

} // Dice

#endif //RAYLIBSTARTER_D10P_H
