#pragma once
#include "GestAnim.h"
class cheminAnim :
    public GestAnim
{
private:
    sf::Vector2f (*fonction)(float);
    float t;
public:

    cheminAnim(GestAnimated* objet, sf::Vector2f (*fonction)(float));
    void update(float dt);
};

