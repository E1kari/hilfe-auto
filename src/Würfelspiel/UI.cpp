//
// Created by Josi on 29.02.2024.
//

#include "UI.h"

UI::UI() {
    infoButton = {static_cast<float>(GetScreenWidth() -100), 0, 100, 100};
    exitButton = {static_cast<float>(GetScreenWidth() -100), static_cast<float>(GetScreenHeight() -100), 100, 100};
    resetButton = {static_cast<float>(GetScreenWidth() -100), static_cast<float>(GetScreenHeight() - 200), 100, 100};

    infoDisplay = false;

    infoText = "Dies ist ein Würfelspiel. Suche dir einen der Würfel, die vor dir liegen aus.\n"
               "Du würfelst indem du auf den Würfel deiner Wahl clickst. Der Computer wird einen Würfel,\n"
               "der gleichen Art benutzen. Wer von euch die höhere Zahl hat, gewinnt einen Punkt.\n"
               "Du darfst so lange weiter spielen wie du möchtest. Möchtest du aufhören, drücke auf den\n"
               "exit Button. Möchtest du den Punktestand zurücksetzen, drücke auf den Reset Button.";

}

UI::PressedButton UI::checkPressedButton() {

    if (CheckCollisionPointRec(GetMousePosition(), infoButton)) {
        pressedButton = UI::infoHover;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            pressedButton = UI::info;
            infoDisplay = !infoDisplay;
        }
    }

    else if (CheckCollisionPointRec(GetMousePosition(), resetButton)) {
        pressedButton = UI::resetHover;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            pressedButton = UI::reset;
        }
    }

    else if (CheckCollisionPointRec(GetMousePosition(), exitButton)) {
        pressedButton = UI::exitHover;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            pressedButton = UI::exit;
        }
    }
    else pressedButton = UI::none;
    return pressedButton;
}

void UI::draw() {
    if (pressedButton == UI::infoHover) {
        DrawRectangleRec(infoButton, GRAY);
    }
    else {
        DrawRectangleRec(infoButton, LIGHTGRAY);
    }

    if (pressedButton == UI::resetHover) {
        DrawRectangleRec(resetButton, GRAY);
    }
    else {
        DrawRectangleRec(resetButton, LIGHTGRAY);
    }

    if (pressedButton == UI::exitHover) {
        DrawRectangleRec(exitButton, GRAY);
    }
    else {
        DrawRectangleRec(exitButton, LIGHTGRAY);
    }

    DrawText("Info", infoButton.x + infoButton.width / 2 - MeasureText("Info", 20) / 2, infoButton.y + infoButton.height / 2 - 10, 20, BLACK);
    DrawText("Exit", exitButton.x + exitButton.width / 2 - MeasureText("Exit", 20) / 2, exitButton.y + exitButton.height / 2 - 10, 20, BLACK);
    DrawText("Reset", resetButton.x + resetButton.width / 2 - MeasureText("Reset", 20) / 2, resetButton.y + resetButton.height / 2 - 10, 20, BLACK);
    displayInfo();

}

void UI::displayInfo() {
    if (!infoDisplay) {
        return;
    }

    ClearBackground(WHITE);
    DrawText(infoText.c_str(), 50, 50, GetScreenHeight() / 30, BLACK);

}

bool UI::getInfoDisplay() {
    return infoDisplay;
}