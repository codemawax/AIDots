#include "Dot.h"

#include "Brain.h"
#include <algorithm>

Dot::Dot(Vector2f position, float radius, Color color)
{
    shape = new CircleShape(radius);
    shape->setFillColor(color);
    shape->setPosition(position);

    brain = new Brain(STEP_NUMBER);
}

Dot::~Dot()
{
    delete(shape);
}

void Dot::Draw(RenderWindow& window)
{
    dotMutex.lock();
    window.draw(*shape);
    dotMutex.unlock();
}

void Dot::Update()
{
    if (currentStep < STEP_NUMBER)
    {
        Vector2f acceleration = brain->GetAccelerationAtStep(currentStep);
        speed += acceleration;
        float maxSpeed{ 4.f };

        // need to fix std::clamp
        if (speed.x > maxSpeed)
        {
            speed.x = maxSpeed;
        }
        if (speed.y > maxSpeed)
        {
            speed.y = maxSpeed;
        }
        if (speed.x < -maxSpeed)
        {
            speed.x = -maxSpeed;
        }
        if (speed.y < -maxSpeed)
        {
            speed.y = -maxSpeed;
        }

        Move(speed);

        currentStep++;
    }
}

void Dot::Move(Vector2f move)
{
    Vector2f position{ shape->getPosition() };
    dotMutex.lock();
    shape->setPosition(position + move);
    dotMutex.unlock();
}
