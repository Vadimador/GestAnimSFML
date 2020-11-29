#pragma once
#include "GestAnim.h"
class SwitchColor :
    public GestAnim
{
private:
    sf::Color finalColor; // la couleur à la fin
    sf::Color startColor; // la couleur au début
    float TempsMax;
    float pourcentTransition = 0.f; // 1 = transition terminée, 0 = transition pas terminée
    float tempsTotal = 0.f;
    
public:
    SwitchColor(GestAnimated* objet, sf::Color Color, float time);
    void update(float deltaTime);
};

