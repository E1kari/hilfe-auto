//
// Created by Josi on 01.03.2024.
//

#include "Sprite.h"

Sprite::Sprite(int _width, int _height, bool _drawable, int _animationFrames) {

    width = _width;
    height = _height;
    drawable = _drawable;
    animationFrames = _animationFrames;
    currentFrame = 0;
    frames = std::vector<Frame>(animationFrames);

}
