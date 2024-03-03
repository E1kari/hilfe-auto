//
// Created by Josi on 01.03.2024.
//

#ifndef RAYLIBSTARTER_LEVEL_H
#define RAYLIBSTARTER_LEVEL_H

#include <vector>
#include <memory>
#include <iostream>
#include "../Raylib_Sprite_Klasse/Sprite.h"

namespace Game {

    class Level {
public:
        Level(int objectAmount);
        Level(int objectAmount, Vector2 velocity);

        void draw();
        void positionRandomly();
        bool checkCollisions(std::shared_ptr<Sprite> sprite);
        void update();
    protected:
        std::vector<std::shared_ptr<Sprite>> sprites_;
    };

} // Game

#endif //RAYLIBSTARTER_LEVEL_H
