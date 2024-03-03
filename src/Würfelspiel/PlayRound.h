//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_PLAYROUND_H
#define RAYLIBSTARTER_PLAYROUND_H

#include <vector>

#include "Dices/BaseDice.h"
#include "Dices/D6.h"
#include "Dices/D8.h"
#include "Dices/D10.h"
#include "Dices/D10p.h"
#include "Dices/D12.h"
#include "Dices/D20.h"

class PlayRound {
public:

    enum DiceIndex {
        d6,
        d8,
        d10,
        d10p,
        d12,
        d20,
    };

    PlayRound();

    std::pair<int, int> update();
    std::pair<int, int> computerRoll();
    void draw();

protected:
    std::vector<Dice::BaseDice *> dices;
    Dice::BaseDice* computer;
    Dice::BaseDice* lastPlayerDice;
};


#endif //RAYLIBSTARTER_PLAYROUND_H
