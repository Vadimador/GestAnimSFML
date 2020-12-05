#include "Clignotement.h"

Clignotement::Clignotement(GestAnimated* objet, float timeClignotement, sf::Color colorClingnotement)
	:GestAnim(objet), finalColor(colorClingnotement), TempsMax(timeClignotement), startColor(objet->getGestColor())
{
}

void Clignotement::update(float deltaTime)
{
	if (this->altern) {
		tempsTotal += deltaTime;
	}
	else
	{
		tempsTotal -= deltaTime;
	}

	if (this->tempsTotal >= this->TempsMax) {
		this->objet->setGestColor(this->finalColor);
		this->altern = false;
		return;
	}
	else if(this->tempsTotal <= 0)
	{
		this->objet->setGestColor(this->startColor);
		this->altern = true;
		return;
	}

	this->pourcentTransition = this->tempsTotal / this->TempsMax;
	this->objet->setGestColor(sf::Color(this->startColor.r + ((this->finalColor.r - this->startColor.r) * this->pourcentTransition),
										this->startColor.g + ((this->finalColor.g - this->startColor.g) * this->pourcentTransition),
										this->startColor.b + ((this->finalColor.b - this->startColor.b) * this->pourcentTransition),
										this->startColor.a + ((this->finalColor.a - this->startColor.a) * this->pourcentTransition)));

}

void Clignotement::firstStart()
{
	this->startColor = this->objet->getGestColor();
}
