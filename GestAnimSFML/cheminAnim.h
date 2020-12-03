#pragma once
#include "GestAnim.h"
class cheminAnim :
    public GestAnim
{
private:
    sf::Vector2f (*fonction)(float);
    float t;
    bool boucle;
    float tend;
    sf::Vector2f positionInitiale;
public:
    ///
    /// \brief explication
    /// \param tend: time end en secondes, negatif si sans fin
    //////
    cheminAnim(GestAnimated* objet,sf::Vector2f (*fonction)(float),float tend, bool boucle=false);

    void firstStart();
    void update(float dt);
};

