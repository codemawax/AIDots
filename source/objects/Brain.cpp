#include "Brain.h"

#include "../utilities/RandomGenerator.h"

Brain::Brain(unsigned int size)
{
    directions = vector<Vector2f>(size);

    for (auto& direction : directions)
    {
        float angle{ RandomGenerator::GetRandomFloat(0.f, static_cast<float>(2.f * _Pi)) };
        direction.x = cos(angle);
        direction.y = sin(angle);
    }
}

Vector2f& Brain::GetAccelerationAtStep(uint step)
{
    Vector2f& direction{ directions.at(step) };
    return direction;
}
