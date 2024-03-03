//
// Created by Josi on 01.03.2024.
//

#include "Level.h"

namespace Game {

    Level::Level(int objectAmount) {
        for (int i = 0; i < objectAmount; i++) {
            sprites_.push_back(std::make_shared<Sprite>(100, 100, "assets/graphics/testimage.png"));
        }
    }

    Level::Level(int objectAmount, Vector2 velocity) {
        for (int i = 0; i < objectAmount; i++) {
            sprites_.push_back(std::make_shared<Sprite>(100, 100, "assets/graphics/testimage.png", velocity, i));
        }
    }

    void Level::draw() {
        for (int i = 0; i < sprites_.size(); i++) {
//            Debug Zeug
//            DrawCircle(sprites_[i]->getHitbox_().center.x, sprites_[i]->getHitbox_().center.y, sprites_[i]->getHitbox_().radius,RED);
//            DrawText(TextFormat("%i", i), sprites_[i]->getPos_x_(), sprites_[i]->getPos_y_(), 20, GRAY);
            DrawTexture(sprites_[i]->getTexture_(), sprites_[i]->getPos_x_(), sprites_[i]->getPos_y_(), BLACK);
        }
    }

    void Level::positionRandomly() {
        for (std::shared_ptr<Sprite> sprite: sprites_) {
            bool valid = false;
            while (!valid) {
                int x = GetRandomValue(0 + sprite->getTexture_().width, GetScreenWidth() - sprite->getTexture_().width);
                int y = GetRandomValue(0 + sprite->getTexture_().height,
                                       GetScreenHeight() - sprite->getTexture_().height);

                sprite->setPos_x_(x);
                sprite->setPos_y_(y);
                Sprite::Circle hitbox_ = {
                        {static_cast<float>(sprite->getPos_x_()), static_cast<float>(sprite->getPos_y_())},
                        static_cast<float>(sprite->getTexture_().width) / 2};
                sprite->setHitbox_(hitbox_);

                valid = !checkCollisions(sprite);

            }
        }

    }

    void Level::update() {
        bool test = false;
        for (std::shared_ptr<Sprite> sprite: sprites_) {
            sprite->positionUpdate();
            test = checkCollisions(sprite);
            if (test){
                sprite->reverseVelocity();
            }
        }
    }


    bool Level::checkCollisions(std::shared_ptr<Sprite> sprite) {
        for (std::shared_ptr<Sprite> spriteCollision : sprites_) {
            if (sprite != spriteCollision &&
                CheckCollisionCircles(sprite->getHitbox_().center, sprite->getHitbox_().radius,
                                      spriteCollision->getHitbox_().center,
                                      spriteCollision->getHitbox_().radius)) {
                // Collision detected, return true
                return true;
            }
        }
        // No collision detected
        return false;
    }


}// Game