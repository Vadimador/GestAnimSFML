#include "GestAnimSFML.h"

std::vector<GestAnim*> GestAnimSFML::listGestAnim;

GestAnimSFML::GestAnimSFML(sf::RenderWindow* window)
{
	GestAnim::initialiserWindow(window);
}

void GestAnimSFML::update(float deltaTime)
{
	for (size_t i = 0; i < GestAnimSFML::listGestAnim.size(); i++)
	{
		if (GestAnimSFML::listGestAnim[i]->getState() == EnumGestAnimState::Animating) {
			GestAnimSFML::listGestAnim[i]->parentUpdate(deltaTime);
		}
		else if (GestAnimSFML::listGestAnim[i]->getState() == EnumGestAnimState::Ending) {
			delete GestAnimSFML::listGestAnim[i];
			GestAnimSFML::listGestAnim.erase(GestAnimSFML::listGestAnim.begin() + i);
			i--;
		}
	}
}

GestAnim* GestAnimSFML::addGestAnimation(GestAnim* gestAnim)
{
	GestAnimSFML::listGestAnim.push_back(gestAnim);
	return gestAnim;
}

void GestAnimSFML::pauseGestAnimation(GestAnim* gestAnim)
{
	gestAnim->pause();
}

void GestAnimSFML::continueGestAnimation(GestAnim* gestAnim)
{
	gestAnim->animate();
}

/*void GestAnimSFML::pauseGestAnimation(int& id)
{
	GestAnimSFML::getGestAnim(id)->pause();
}*/

/*GestAnim* GestAnimSFML::getGestAnim(int id)
{
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++)
	{
		if ((*it)->getID() == id) {
			return *it;
		}
	}
	return nullptr;
}*/

void GestAnimSFML::Delete(GestAnim* gestAnim)
{
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++)
	{
		if (*it == gestAnim) {
			delete *it;
			GestAnimSFML::listGestAnim.erase(it);
			break;
		}
	}

}

void GestAnimSFML::Delete(int id)
{
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++)
	{
		if ((*it)->getID() == id) {
			delete* it;
			GestAnimSFML::listGestAnim.erase(it);
			break;
		}
	}
}

GestAnimSFML::~GestAnimSFML()
{
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++)
	{
		delete	(*it);
	}
}
