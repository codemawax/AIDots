#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <thread>
#include <iostream>

#include "objects/Dot.h"

bool isRunning{ true };

void Update(Dot& dot)
{
    sf::Clock clock;
    sf::Time lastUpdateTime;

    while (isRunning)
    {
        sf::Time currentTime = clock.getElapsedTime();
        
        if (currentTime.asMilliseconds() - lastUpdateTime.asMilliseconds() > 25)
        {
            float distanceRatio{ 10.f };
            float xMove{ (2.f * static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) - 1.f };
            float yMove{ (2.f * static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) - 1.f };
            sf::Vector2f move(xMove * distanceRatio, yMove * distanceRatio);
            dot.Move(sf::Vector2f(move));

            lastUpdateTime = currentTime;
        }
    }
}

void Draw(Dot& dot)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "AIDots");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                isRunning = false;
            }
        }

        window.clear(sf::Color::White);
        dot.Draw(window);
        window.display();
    }
}

int main()
{
    Dot dot(sf::Vector2f(400.f, 400.f), 5.f, sf::Color::Red);

    std::thread drawThread(Draw, std::ref(dot));
    std::thread updateThread(Update, std::ref(dot));

    drawThread.join();
    updateThread.join();

    return 0;
}