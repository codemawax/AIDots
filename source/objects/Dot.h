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
    inline bool IsAlive() { return alive; }
    void CalculateFitness();

private:
    void Move(Vector2f move);

    Vector2f speed{};
    mutex dotMutex;
    Shape* shape;
    Brain* brain;
    uint currentStep{};
    bool alive{true};
    bool hasReachedGoal{};
    float fitness{};
    Vector2f goal{ 400.f, 0.f };

    const uint STEP_NUMBER{400};
};

