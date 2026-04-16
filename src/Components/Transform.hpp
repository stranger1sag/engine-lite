#pragma once
#include "include/Vector.hpp"

struct Transform
{
    Vector3f position = Vector3f::ZERO;
    Vector2f size = Vector2f::ONE;
    Vector2f scale = Vector2f::ONE;
    float rotation = 0.f;
};
