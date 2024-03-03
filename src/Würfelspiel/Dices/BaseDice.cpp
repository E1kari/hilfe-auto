//
// Created by Josi on 29.02.2024.
//

#include "BaseDice.h"
#include <random>
#include <iostream>

namespace Dice {
    BaseDice::BaseDice(int _sides, std::vector<int> _faces, std::string _texturePath, int _textSize, Vector2 _position, std::string _name) {

        texturePath = _texturePath;
        texture = LoadTexture(texturePath.c_str());
        Image image = LoadImageFromTexture(this -> texture);

        sides = _sides;
        faces = _faces;
        textSize = _textSize;
        dicePosition = {_position.x - texture.width/2, _position.y + texture.height/2};
        collisionType = CollisionType::noCollision;
        lastResultIndex = sides - 1;
        name = _name;

        hitbox = std::vector<std::vector<bool>>(image.height, std::vector<bool>(image.width));


        for (int y = 0; y < image.height; y++) {
            for (int x = 0; x < image.width; x++) {
                if (GetImageColor(image , x, y).a == 0) {
                    hitbox[y][x] = false;
                }
                else {
                    hitbox[y][x] = true;
                }
            }

        }
    }

    void BaseDice::draw() {

        Vector2 textPosition = {dicePosition.x + texture.width/2 - MeasureText(TextFormat("%d", faces[lastResultIndex]), textSize)/2, dicePosition.y + texture.height/2 - textSize/2};
        Color diceColor;

//        DrawText(TextFormat(" %n: %c",name.c_str(), collisionType), textPosition.x, textPosition.y - 200, textSize, RED);

        switch (collisionType) {
            case CollisionType::click:
                diceColor = WHITE;
                break;
            case CollisionType::hover:
                diceColor = DARKGRAY;
                break;
            case CollisionType::noCollision:
                diceColor = BLACK;
                break;
        }

        DrawTexture(texture, dicePosition.x, dicePosition.y, diceColor);
        DrawText(TextFormat("%d", faces[lastResultIndex]), textPosition.x, textPosition.y, textSize, LIGHTGRAY);
        DrawText(TextFormat(name.c_str()), dicePosition.x + texture.width/2 - MeasureText(TextFormat(name.c_str()), textSize)/2, dicePosition.y + texture.height + 10, textSize, LIGHTGRAY);


    }

    int BaseDice::roll() {
        //% is range
        lastResultIndex = std::rand() % faces.size();
        return faces[lastResultIndex];
    }

    BaseDice::CollisionType Dice::BaseDice::checkCollision(Vector2 _position) {

        // for some reaon the rectangle is one pixel too wide

        collisionType = CollisionType::noCollision;
        //check if curser in image rectangle via raylibs rectangle collision check (prevents trying to access out of bounds
        if (CheckCollisionPointRec(_position, {static_cast<float>(dicePosition.x), static_cast<float>(dicePosition.y),
                                               static_cast<float>(texture.width -1),
                                               static_cast<float>(texture.height)})) {

            //if that is the case use the hitbox to check if the curser is on a non-transparent pixel
            if (hitbox[_position.x - dicePosition.x][_position.y - dicePosition.y]) {
                collisionType = CollisionType::hover;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    collisionType = CollisionType::click;
                }
            }
            else {
                collisionType = CollisionType::noCollision;
            }
        }
        return collisionType;
    }

    BaseDice::CollisionType Dice::BaseDice::getCollisionType(){
        return collisionType;
    }

    int BaseDice::getLastResultIndex() {
        return lastResultIndex;
    }



} // Dice