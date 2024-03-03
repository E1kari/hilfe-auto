
#include "config.h"
#include "Würfelspiel.h"

#include <cstdlib>
#include "raylib.h"

#include "UI.h"
#include "PlayRound.h"


int Würfelspiel::würfelspielMain() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(GetScreenWidth(), GetScreenHeight(), Game::PROJECT_NAME);
    SetTargetFPS(60);
    enum LastWinner {
        none,
        player,
        draw,
        computer
    };

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
   LastWinner lastWinner = none;
   std::string winnerText = "";

    UI ui = UI();
    PlayRound playRound = PlayRound();

    UI::PressedButton uiButton = UI::PressedButton::none;

    int playerScore = 0;
    int computerScore = 0;


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        //Updates that are made by frame are coded here

        uiButton = ui.checkPressedButton();
        if (uiButton == UI::PressedButton::info) {
            ui.displayInfo();
        }
        if (uiButton == UI::PressedButton::exit) {
            break;
        }
        if (uiButton == UI::PressedButton::reset) {
            playerScore = 0;
            computerScore = 0;
        }

        else {
            std::pair <int, int> result = playRound.update();
            if (result.first == 1 && result.second == 0) {
                lastWinner = player;
            }
            if (result.first == 1 && result.second == 1) {
                lastWinner = draw;
            }
            if (result.first == 0 && result.second == 1) {
                lastWinner = computer;
            }
            playerScore += result.first;
            computerScore += result.second;
        }
        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()

        ClearBackground(WHITE);
        ui.draw();
        if (!ui.getInfoDisplay()) {
            playRound.draw();

            DrawText(("Computer: " + std::to_string(computerScore)).c_str(), 10, 10, 50, BLACK);
            DrawText(("Player: " + std::to_string(playerScore)).c_str(), 10, GetScreenHeight() - 60, 50, BLACK);

            switch (lastWinner) {
                case none:
                    winnerText = "";
                    break;
                case player:
                    winnerText = "You win!";
                    break;
                case draw:
                    winnerText = "Draw!";
                    break;
                case computer:
                    winnerText = "You lose!";
                    break;
            }
            //Draw winner text centred on screen
            DrawText(winnerText.c_str(), GetScreenWidth() / 2 - MeasureText(winnerText.c_str(), 50) / 2, GetScreenHeight() / 2 + 50, 50, BLACK);
        }


        EndDrawing();
    } // Main game loop end

    // De-initialization here


    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
