#include "cheminAnim.h"

cheminAnim::cheminAnim(GestAnimated* objet, sf::Vector2f (*fonction)(float))
	:GestAnim(objet)
{
	this->fonction = fonction;
	t = 0.f;
}

void cheminAnim::update(float dt)
{
	t += dt;
	this->objet->setGestPosition(fonction(t));
}
