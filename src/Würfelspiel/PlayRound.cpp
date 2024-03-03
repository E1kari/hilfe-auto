//
// Created by Josi on 29.02.2024.
//

#include "PlayRound.h"


PlayRound::PlayRound() {

    int diceAmount = 6; // >13 nicht empholen, der Text wird unleserlich

    dices.push_back(new Dice::D6(Vector2{static_cast<float>(GetScreenWidth() * 1 / (diceAmount + 1)), static_cast<float>(GetScreenHeight() * 2 / 3)}));
    dices.push_back(new Dice::D8(Vector2{static_cast<float>(GetScreenWidth() * 2 / (diceAmount + 1)), static_cast<float>(GetScreenHeight() * 2 / 3)}));
    dices.push_back(new Dice::D10(Vector2{static_cast<float>(GetScreenWidth() * 3 / (diceAmount + 1)),static_cast<float>(GetScreenHeight() * 2 / 3)}));
    dices.push_back(new Dice::D10p(Vector2{static_cast<float>(GetScreenWidth() * 4 / (diceAmount + 1)),static_cast<float>(GetScreenHeight() * 2 / 3)}));
    dices.push_back(new Dice::D12(Vector2{static_cast<float>(GetScreenWidth() * 5 / (diceAmount + 1)),static_cast<float>(GetScreenHeight() * 2 / 3)}));
    dices.push_back(new Dice::D20(Vector2{static_cast<float>(GetScreenWidth() * 6 / (diceAmount + 1)),static_cast<float>(GetScreenHeight() * 2 / 3)}));

    computer = new Dice::D6(Vector2{static_cast<float>(GetScreenWidth() * 1 / 2), static_cast<float>(GetScreenHeight() * 1 / 3)});

}

std::pair<int, int> PlayRound::update() {
    for (Dice::BaseDice* dice: dices) {
        if (dice->checkCollision(GetMousePosition()) == Dice::BaseDice::CollisionType::click) {
            dice->roll();
            lastPlayerDice = dice;
            computer = dice->createComputerDice();
        return computerRoll();
        }

    }
    return {0, 0};
}

std::pair<int, int> PlayRound::computerRoll() {
    computer->roll();
    if (lastPlayerDice->getLastResultIndex() > computer->getLastResultIndex()) {
        return {1, 0};
    }
    if (lastPlayerDice->getLastResultIndex() == computer->getLastResultIndex()) {
        return {1, 1};
    }
    if (lastPlayerDice->getLastResultIndex() < computer->getLastResultIndex()) {

        return {0, 1};
    }
    return {0, 0};
}


void PlayRound::draw() {
    for (Dice::BaseDice* dice : dices) {
        dice->draw();
    }
    computer->draw();

}

