#include "testanim.h"

testanim::testanim(GestAnimated* objet)
	:GestAnim(objet)
{
	objet->setGestPosition(sf::Vector2f((this->getSizeWindow().x / 2) - (objet->getGestSize().x/2), (this->getSizeWindow().y / 2) - (objet->getGestSize().y / 2)));
	this->stop();
}

void testanim::update(float deltaTime)
{
}
