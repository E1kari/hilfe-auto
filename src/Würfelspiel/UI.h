//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_UI_H
#define RAYLIBSTARTER_UI_H


#include <string>
#include "raylib.h"

class UI {
public:

    enum PressedButton {
        none,
        infoHover,
        info,
        resetHover,
        reset,
        exitHover,
        exit
    };

    UI();

    void draw();
    void displayInfo();
    PressedButton checkPressedButton();

    bool getInfoDisplay();

protected:

    Rectangle infoButton;
    Rectangle exitButton;
    Rectangle resetButton;

    bool infoDisplay;

    PressedButton pressedButton;

    std::string infoText;

};


#endif //RAYLIBSTARTER_UI_H
