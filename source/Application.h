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
    void Draw(sf::RenderWindow& window);

private:
    void UpdateDots();

    std::vector<std::unique_ptr<Dot>> dots;

    sf::Clock clock;
    sf::Time lastUpdateTime;
};