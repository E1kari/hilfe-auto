

#include <cstdlib>
#include <iostream>
#include <limits>
#include "raylib.h"
#include "config.h"
#include "Würfelspiel/Würfelspiel.h"
#include "Eine_Level_Klasse/Eine_Level_Klasse.h"

int main() {
    bool running = true;
    bool levelKlasseSelection = false;
    Würfelspiel würfelspiel;
    Game::Eine_Level_Klasse eineLevelKlasse;

    while (running) {
        int choice;
        while (std::cout << "\nDies ist die Auswahl an Uebungen, die Sie aufrufen koennen: \n"
                            "0. Beenden \n"
                            "1. Wuerfelspiel \n"
                            "2. Eine Level Klasse \n"
                            "Bitte gib den Index der zu startenden Uebung ein: \n\n" && !(std::cin >> choice)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "Das ist keine Zahl.\n";
        }
        switch (choice) {
            case 0:
                running = false;
                break;
            case 1:
                würfelspiel.würfelspielMain();
                break;
            case 2:
                int choice2;
                levelKlasseSelection = true;
                while (levelKlasseSelection) {
                    levelKlasseSelection = false;
                    while (std::cout << "\nDies ist die Auswahl an Startbedingungen, die Sie aufrufen koennen: \n"
                                        "0. Zurueck \n"
                                        "1. colliding \n"
                                        "2. random placement 30 seconds \n"
                                        "3. random placement on click \n"
                                        "Bitte gib den Index der zu startenden Uebung ein: \n\n" &&
                           !(std::cin >> choice2)) {
                        std::cin.clear(); //clear bad input flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                        std::cout << "Das ist keine Zahl.\n";
                    }
                    switch (choice2) {
                        case 0:
                            break;
                        case 1:
                            eineLevelKlasse.Eine_Level_KlasseMain(Game::State::colliding);
                            break;
                        case 2:
                            eineLevelKlasse.Eine_Level_KlasseMain(Game::State::random30sec);
                            break;
                        case 3:
                            eineLevelKlasse.Eine_Level_KlasseMain(Game::State::randomOnClick);
                            break;
                        default:
                            std::cout << "Ungueltiger Index. Bitte versuchen Sie es erneut.\n";
                            levelKlasseSelection = true;
                            break;
                    }
                }
                break;

            default:
                std::cout << "Ungueltiger Index. Bitte versuchen Sie es erneut.\n";
        }
    }
}


//  (x) Aufgabe 1 - PAP
//  (x) Aufgabe 2 - Sprite
//  (x) Aufgabe 3 - Würfelspiel
//  ( ) Aufgabe 4 - Pflanzenklasse
//  ( ) Aufgabe 5 - Custom Dynamic Array | ( ) a) | ( ) b)
//  ( ) Aufgabe 6 - Auto
//  (x) Aufgabe 7 - Raylib Sprite Klasse
//  (x) Aufgabe 8 - Eine Level Klasse | (x) a) | (x) b) | (x) c)