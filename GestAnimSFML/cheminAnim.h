#pragma once
#include "GestAnim.h"
class cheminAnim :
    public GestAnim
{
private:
    sf::Vector2f (*fonction)(double);
    double t;
public:

    cheminAnim(GestAnimated* objet, sf::Vector2f (*fonction)(double));
    void update(float dt);
};

