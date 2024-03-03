//
// Created by Josi on 01.03.2024.
//

#ifndef RAYLIBSTARTER_SPRITE_H
#define RAYLIBSTARTER_SPRITE_H


#include <string>
#include "raylib.h"

namespace Game {

    class Sprite {
    public:

        Sprite(float pos_x, float pos_y, std::string texturePath, Vector2 velocity, int _index);

        struct Circle{
            Vector2 center;
            float radius;
        };

        Sprite(float pos_x, float pos_y, Texture2D texture);
        Sprite(float pos_x, float pos_y, std::string texturePath);
        Sprite(float pos_x, float pos_y, std::string texturePath, Vector2 velocity);
        void init();

        ~Sprite();

        void positionUpdate();
        void reverseVelocity();


        int getPos_x_();
        int getPos_y_();
        Texture2D getTexture_();
        Circle getHitbox_();

        void setPos_x_(int pos_x);
        void setPos_y_(int pos_y);
        void setHitbox_(Circle hitbox);

    protected:
        int index;

        float pos_x_;
        float pos_y_;
        float velocity_x_;
        float velocity_y_;
        Texture2D texture_;
        Circle hitbox_;

        void init(float pos_x, float pos_y);
    };
}

#endif //RAYLIBSTARTER_SPRITE_H
