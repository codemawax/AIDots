#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <thread>
#include <iostream>

#include "Application.h"

bool isRunning{ true };

void Update(Application& app)
{
    while (isRunning)
    {
        app.Update();
    }
}

void Draw(sf::RenderWindow& window, Application& app)
{
    while (isRunning)
    {
        window.clear(sf::Color::White);
        app.Draw(window);
        window.display();
    }
}

int main()
{
    Application app;

    sf::RenderWindow window(sf::VideoMode(800, 800), "AIDots");
    window.setActive(false);

    std::thread drawThread(Draw, std::ref(window), std::ref(app));
    std::thread updateThread(Update, std::ref(app));

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
    }

    updateThread.join();
    drawThread.join();

    return 0;
}
