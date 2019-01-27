#pragma once

#include "../Utils.h"
#include <random>

class RandomGenerator
{
public:
    static float GetRandomFloat(float min, float max);

private:
    static mt19937& GetRandomEngine();
};