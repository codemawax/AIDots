#pragma once

#include <memory>
#include "objects/Dot.h"

namespace sf
{
    class RenderWindow;
}

class Application
{
public:
    Application();
    void Update();
    void Draw(RenderWindow& window);

private:
    void UpdateDots();
    void CreateNewGeneration();

    vector<unique_ptr<Dot>> dots;

    Clock clock;
    Time lastUpdateTime;

    uint generationCount{};

    bool areAllDotsDead{};
};