#pragma once
#include "GestAnim.h"
class Clignotement :
    public GestAnim
{
private:
    sf::Color finalColor; // la couleur à la fin
    sf::Color startColor; // la couleur au début
    float TempsMax;
    float pourcentTransition = 0.f; // 1 = transition terminée, 0 = transition pas terminée
    float tempsTotal = 0.f;
    bool altern = true;
public:
    Clignotement(GestAnimated* objet, float timeClignotement, sf::Color colorClingnotement = sf::Color::Transparent);
    void update(float deltaTime);
};

