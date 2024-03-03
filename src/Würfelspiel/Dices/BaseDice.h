//
// Created by Josi on 29.02.2024.
//

#ifndef RAYLIBSTARTER_BASEDICE_H
#define RAYLIBSTARTER_BASEDICE_H

#include <vector>
#include <string>
#include "raylib.h"

namespace Dice {

    class BaseDice {
    public:

        enum CollisionType {
            noCollision,
            hover,
            click
        };

        BaseDice(int _sides, std::vector<int> _faces, std::string _texturePath, int _textSize, Vector2 _position, std::string _name);
        int roll();
        void draw();
        CollisionType checkCollision(Vector2 _position);

        CollisionType getCollisionType();
        int getLastResultIndex();
        std::string getName();

        virtual BaseDice* createComputerDice() = 0;

    protected:
        std::vector <std::vector <bool>> hitbox;
        CollisionType collisionType;

        Vector2 dicePosition;
        std::string texturePath;
        Texture2D texture;
        int sides;
        std::vector<int> faces;
        int lastResultIndex;
        int textSize;
        std::string name;
    };

} // Dice

#endif //RAYLIBSTARTER_BASEDICE_H
