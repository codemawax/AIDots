#include "Application.h"

Application::Application()
{
    sf::Vector2f initialPosition(400.f, 400.f);
    float radius{ 2.f };
    sf::Color color{ sf::Color::Red };

    for (unsigned int i = 0; i < 1000; ++i)
    {
        dots.push_back(std::unique_ptr<Dot>(new Dot(initialPosition, radius, color)));
    }
}

void Application::Update()
{
    sf::Time currentTime = clock.getElapsedTime();

    if (currentTime.asMilliseconds() - lastUpdateTime.asMilliseconds() > 10)
    {
        UpdateDots();
        lastUpdateTime = currentTime;
    }
}

void Application::Draw(sf::RenderWindow& window)
{
    for (auto& dot : dots)
    {
        if (dot)
        {
            dot.get()->Draw(window);
        }
    }
}

void Application::UpdateDots()
{
    for (auto& dot : dots)
    {
        if (dot)
        {
            dot.get()->Update();
        }
    }
}
