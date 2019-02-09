#pragma once

class Collider
{
public:
    virtual bool IsColliding(Collider& other) = 0;
};