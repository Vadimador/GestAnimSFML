#include "GestAnim.h"
#include "GestAnimSFML.h"

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

void GestAnim::parentUpdate(float deltaTime)
{
	if (this->isStarted) {
		this->update(deltaTime);
	}
	else
	{
		this->firstStart();
		this->update(deltaTime);
		this->isStarted = true;
	}
}

void GestAnim::firstStart()
{
}

void GestAnim::end()
{
	this->setState(EnumGestAnimState::Ending);
}

void GestAnim::pause()
{
	this->setState(EnumGestAnimState::Waiting);
}

void GestAnim::animate()
{
	this->setState(EnumGestAnimState::Animating);
}

GestAnim* GestAnim::nextGestAnimation(GestAnim* gestAnim)
{
	gestAnim->pause();
	GestAnimSFML::addGestAnimation(gestAnim);
	this->listNextAnim.push_back(gestAnim);
	return gestAnim;
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
	for (auto& i : this->listNextAnim)
	{
		i->animate();
	}

	if (this->objet->IsEncapsulator()) { // si la classe est une classe d'encapsulation
		delete this->objet;
	}
}
