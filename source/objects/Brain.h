#pragma once

#include "../Utils.h"

class Brain
{
public:
    Brain() = delete;
    Brain(unsigned int size);

    Vector2f& GetAccelerationAtStep(uint step);

private:
    vector<Vector2f> directions;
    uint currentIndex{};
};
