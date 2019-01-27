#include "RandomGenerator.h"

float RandomGenerator::GetRandomFloat(float min, float max)
{
    uniform_real_distribution<> distribution(min, max);
    mt19937& randomEngine{ GetRandomEngine() };
    return distribution(randomEngine);
}

mt19937& RandomGenerator::GetRandomEngine()
{
    static random_device randomDevice;
    static mt19937 generator(randomDevice());
    return generator;
}
