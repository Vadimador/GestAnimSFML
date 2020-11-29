#pragma once
#include "GestAnim.h"
class Clignotement :
    public GestAnim
{
private:
    sf::Color finalColor; // la couleur � la fin
    sf::Color startColor; // la couleur au d�but
    float TempsMax;
    float pourcentTransition = 0.f; // 1 = transition termin�e, 0 = transition pas termin�e
    float tempsTotal = 0.f;
    bool altern = true;
public:
    Clignotement(GestAnimated* objet, float timeClignotement, sf::Color colorClingnotement = sf::Color::Transparent);
    void update(float deltaTime);
};

