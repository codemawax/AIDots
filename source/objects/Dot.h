#pragma once

#include <SFML/Graphics.hpp>
#include <mutex>

class Dot
{
public:
    Dot(sf::Vector2f position, float radius, sf::Color color);
    ~Dot();
    void Draw(sf::RenderWindow& window);
    void Update();

private:
    void Move(sf::Vector2f move);

    std::mutex mutex;
    sf::Shape* shape;
};

