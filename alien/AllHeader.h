#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

inline Vector2f normalize(Vector2f vec)
{
    float len = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (len != 0)
        return vec / len;
    return vec;
}

inline float distance(Vector2f p1, Vector2f p2)
{
    Vector2f vec = p1 - p2;
    float len = sqrtf(vec.x * vec.x + vec.y * vec.y);
    return len;
}
