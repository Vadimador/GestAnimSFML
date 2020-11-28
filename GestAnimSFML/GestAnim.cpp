#include "GestAnim.h"
int GestAnim::IdCompteur = 0;
sf::RenderWindow* GestAnim::window = nullptr;

sf::Vector2u GestAnim::getSizeWindow()
{
	return this->window->getSize();
}

void GestAnim::setState(EnumGestAnimState&& state)
{
	this->state = std::move(state);
}

void GestAnim::initialiserWindow(sf::RenderWindow* window)
{
	if (GestAnim::window == nullptr) {
		GestAnim::window = window;
	}
}

GestAnim::GestAnim(GestAnimated* objet)
	:objet(objet), state(EnumGestAnimState::Animating)
{
	this->id = GestAnim::IdCompteur; // initialisation d'un compteur qui sera différent pour chaque anim
	IdCompteur++;
}

void GestAnim::stop()
{
	this->setState(EnumGestAnimState::Ending);
}

int GestAnim::getID()
{
	return this->id;
}

EnumGestAnimState GestAnim::getState()
{
	return this->state;
}

GestAnim::~GestAnim()
{
	if (this->objet->IsEncapsulator()) { // si la classe est une classe d'encapsulation
		delete this->objet;
	}
}
