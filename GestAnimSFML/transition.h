#pragma once
#include "GestAnim.h"

class transition :
    public GestAnim
{
private:
    sf::Vector2f (*trajectoire)(float);
    GestAnimated* objet;
    float t;
    float tend;
    sf::Vector2f positionInitiale;
    sf::Vector2f positionFin;
public:
    ///
    /// \brief explication
    /// \param tend: temps de fin de la trajectoire en secondes trajectoire: fonction du temps allant de (0,0) a (1,0)
    //////
    transition(GestAnimated* objet, sf::Vector2f(*trajectoire)(float), sf::Vector2f positionFin, float tend);
    void update(float dt);
    void firstStart();
};

