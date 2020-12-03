#include "cheminAnim.h"

cheminAnim::cheminAnim(GestAnimated* objet, sf::Vector2f (*fonction)(float), float tend, bool boucle)
	:GestAnim(objet)
{
	this->fonction = fonction;
	t = 0.f;
	this->tend = tend;
	this->boucle = boucle;
	positionInitiale = objet->getGestPosition();
}

void cheminAnim::firstStart()
{
	positionInitiale = objet->getGestPosition();
}

void cheminAnim::update(float dt)
{
	t += dt;
	if (tend>0 && t > tend) {
		if (boucle) {
			t = 0.f;
		}
		else {
			this->end();
			return;
		}
	}
	this->objet->setGestPosition(positionInitiale + fonction(t));
}
