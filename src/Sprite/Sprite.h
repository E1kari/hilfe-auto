//
// Created by Josi on 01.03.2024.
//

#ifndef RAYLIBSTARTER_SPRITE_H
#define RAYLIBSTARTER_SPRITE_H


#include <vector>
#include "Frame.h"

class Sprite {
public:

    struct coordinates3 {
        int x;
        int y;
        int z;
    };

    enum State {
        animate,
        character,
        object,
        character_animation,
    };

    Sprite(int _width, int _height, bool _drawable, int _animationFrames);

protected:

int width;
int height;
bool drawable;
int animationFrames;
int currentFrame;
std::vector<Frame> frames;
};


#endif //RAYLIBSTARTER_SPRITE_H
