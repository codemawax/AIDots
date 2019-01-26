#include "Dot.h"

Dot::Dot(sf::Vector2f position, float radius, sf::Color color)
{
    shape = new sf::CircleShape(radius);
    shape->setFillColor(color);
    shape->setPosition(position);
}

Dot::~Dot()
{
    delete(shape);
}

void Dot::Draw(sf::RenderWindow& window)
{
    mutex.lock();
    window.draw(*shape);
    mutex.unlock();
}

void Dot::Move(sf::Vector2f move)
{
    sf::Vector2f position{ shape->getPosition() };
    mutex.lock();
    shape->setPosition(position + move);
    mutex.unlock();
}
