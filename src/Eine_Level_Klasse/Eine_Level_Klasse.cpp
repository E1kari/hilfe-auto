//
// Created by Josi on 02.03.2024.
//

#include "config.h"
#include <cstdlib>
#include "raylib.h"

#include "Eine_Level_Klasse.h"
#include "Level.h"

namespace Game {

    int Eine_Level_Klasse::Eine_Level_KlasseMain(Game::State _state) {

        // Raylib initialization
        // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
        InitWindow(GetScreenWidth(), GetScreenHeight(), Game::PROJECT_NAME);
        SetTargetFPS(60);

        // Your own initialization code here

        Game::State state = _state;

        Level* level;
        bool positonRandomly;
        int frameCount;

        switch (state) {
            case debug: {
                level = new Level(3, {20, 20});
                positonRandomly = false;
                break;
            }
            case colliding: {
                level = new Level(20);
                positonRandomly = false;
                break;
            }
            case random30sec: {
                level = new Level(20);
                frameCount = 0;
                break;
            }
            case randomOnClick: {
                level = new Level(20);
                break;
            }
        }

        // Main game loop
        while (!WindowShouldClose()) // Detect window close button or ESC key
        {
//            //Updates that are made by frame are coded here
            switch (state) {
                case debug || colliding:
                    if (!positonRandomly) {
                        level->positionRandomly();
                        positonRandomly = true;
                    }
                    level->update();
                    break;
                case random30sec:
                    frameCount++;
                    if (frameCount % 30 == 0) {
                        level->positionRandomly();
                    }
                    break;
                case randomOnClick:
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        level->positionRandomly();
                    }
                    break;
            }


            BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()

            ClearBackground(WHITE);
            level->draw();

            EndDrawing();
        } // Main game loop end

        // De-initialization here


        // Close window and OpenGL context
        CloseWindow();

        return EXIT_SUCCESS;
    }

} // Game