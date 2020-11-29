#include "SwitchColor.h"

SwitchColor::SwitchColor(GestAnimated* objet, sf::Color color, float time)
	:GestAnim(objet), finalColor(color), TempsMax(time), startColor(objet->getGestColor())
{

}

void SwitchColor::update(float deltaTime)
{
	tempsTotal += deltaTime;
	if (this->tempsTotal >= this->TempsMax) {
		this->objet->setGestColor(this->finalColor);
		this->stop();
	}
	else
	{
		this->pourcentTransition = this->tempsTotal / this->TempsMax;
		this->objet->setGestColor(sf::Color(this->startColor.r + ((this->finalColor.r - this->startColor.r) * this->pourcentTransition),
											this->startColor.g + ((this->finalColor.g - this->startColor.g) * this->pourcentTransition),
											this->startColor.b + ((this->finalColor.b - this->startColor.b) * this->pourcentTransition),
											this->startColor.a + ((this->finalColor.a - this->startColor.a) * this->pourcentTransition)));
	}
	
}
