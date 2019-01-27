#pragma once

#include "../Utils.h"
#include <mutex>

class Brain;

class Dot
{
public:
    Dot(Vector2f position, float radius, Color color);
    ~Dot();
    void Draw(RenderWindow& window);
    void Update();

private:
    void Move(Vector2f move);

    Vector2f speed{};
    mutex dotMutex;
    Shape* shape;
    Brain* brain;
    uint currentStep{};

    const uint STEP_NUMBER{400};
};

