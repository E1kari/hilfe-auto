//
// Created by Josi on 01.03.2024.
//

#include "Sprite.h"
namespace Game {


    Sprite::Sprite(float pos_x, float pos_y, Texture2D texture) {
        texture_ = texture;
        init(pos_x, pos_y);
    }

    Sprite::Sprite(float pos_x, float pos_y, std::string texturePath) {
        texture_ = LoadTexture(texturePath.c_str());
        init(pos_x, pos_y);
    }
    Sprite::Sprite(float pos_x, float pos_y, std::string texturePath, Vector2 velocity, int _index) {
        texture_ = LoadTexture(texturePath.c_str());
        pos_x_ = pos_x;
        pos_y_ = pos_y;
        hitbox_ = {{pos_x, pos_y}, static_cast<float>(texture_.width / 2)};

        velocity_x_ = 20;
        velocity_y_ = 20;
        index = _index;
    }

    void Sprite::init(float pos_x, float pos_y) {
        pos_x_ = pos_x;
        pos_y_ = pos_y;
        hitbox_ = {{pos_x, pos_y}, static_cast<float>(texture_.width / 2)};
        float randVelocity = GetRandomValue(-10, 10);
        if (randVelocity == 0) {
            randVelocity = 5;
        }

        velocity_x_ = randVelocity;
        velocity_y_ = randVelocity;
    }

    void Sprite::positionUpdate() {

        if (pos_x_ >= GetScreenWidth() - texture_.width || pos_x_ <= 0) {
            velocity_x_ *= -1;
        }

        if (pos_y_ >= GetScreenHeight() - texture_.height || pos_y_ <= 0) {
            velocity_y_ *= -1;
        }

        pos_x_ += velocity_x_;
        pos_y_ += velocity_y_;

        hitbox_ = {{pos_x_+ texture_.width/2, pos_y_ + texture_.height/2}, static_cast<float>(texture_.width / 2)};

    }

    void Sprite::reverseVelocity() {
        velocity_x_ *= -1;
        velocity_y_ *= -1;
    }

    Sprite::~Sprite() {
        UnloadTexture(texture_);
    }

    int Sprite::getPos_x_() {
        return pos_x_;
    }

    int Sprite::getPos_y_() {
        return pos_y_;
    }

    Texture2D Sprite::getTexture_() {
        return texture_;
    }

    Sprite::Circle Sprite::getHitbox_() {
        return hitbox_;
    }

    void Sprite::setPos_x_(int pos_x) {
        pos_x_ = pos_x;
    }

    void Sprite::setPos_y_(int pos_y) {
        pos_y_ = pos_y;
    }

    void Sprite::setHitbox_(Sprite::Circle hitbox) {
        hitbox_ = hitbox;
    }




}


