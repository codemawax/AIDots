#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
using uint = unsigned int;

float GetDistance(Vector2f a, Vector2f b)
{
    return sqrt(pow(a.x + b.x, 2.f) + (a.y + b.y, 2.f));
}