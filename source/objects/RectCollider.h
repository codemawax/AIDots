#pragma once

#include "Collider.h"
#include "../Utils.h"

class RectCollider : public Collider
{
public:
    bool IsColliding(Collider& other) override;

private:
    FloatRect rectangle;
};