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

void Dot::Update()
{
    float distanceRatio{ 1.f };
    float xMove{ (2.f * static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) - 1.f };
    float yMove{ (2.f * static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) - 1.f };
    sf::Vector2f move(xMove * distanceRatio, yMove * distanceRatio);
    Move(sf::Vector2f(move));
}

void Dot::Move(sf::Vector2f move)
{
    sf::Vector2f position{ shape->getPosition() };
    mutex.lock();
    shape->setPosition(position + move);
    mutex.unlock();
}
