#pragma once

#include <SFML/Graphics.hpp>
#include <mutex>

class Dot
{
public:
    Dot(sf::Vector2f position, float radius, sf::Color color);
    ~Dot();
    void Draw(sf::RenderWindow& window);
    void Move(sf::Vector2f move);

private:
    std::mutex mutex;
    sf::Shape* shape;
};

