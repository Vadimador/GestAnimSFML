#include "testanim.h"


testanim::testanim(GestAnimated* objet)
	:GestAnim(objet)
{
	
}

void testanim::update(float deltaTime)
{
	//this->objet->setGestPosition(sf::Vector2f((this->getSizeWindow().x / 2) - (objet->getGestSize().x / 2), (this->getSizeWindow().y / 2) - (objet->getGestSize().y / 2)));
	this->objet->setGestPosition(sf::Vector2f(this->objet->getGestPosition().x + (0.05f * deltaTime), this->objet->getGestPosition().y + (0.05f * deltaTime)));
	//this->stop();
}
