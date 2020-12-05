#include "transition.h"
#include <iostream>

transition::transition(GestAnimated* objet, sf::Vector2f(*trajectoire)(float), sf::Vector2f positionFin,float tend):
	GestAnim(objet)
{
	this->objet = objet;
	this->trajectoire = trajectoire;
	this->positionFin = positionFin;
	t = 0.f;
	this->tend = tend;
	positionInitiale = objet->getGestPosition();
}

void transition::update(float dt)
{
	t += dt;
	if (t > tend) {
		this->end();
		return;
	}
	sf::Vector2f point = trajectoire(t);
	float Dx = positionFin.x - positionInitiale.x; float Dy = positionFin.y - positionInitiale.y;
	this->objet->setGestPosition(positionInitiale+sf::Vector2f(point.x*Dx - point.y*Dy, Dx*point.y + Dy*point.x));
}

void transition::firstStart()
{
	positionInitiale = objet->getGestPosition();
}
