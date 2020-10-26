#include "GestAnimSFML.h"

std::vector<GestAnim*> GestAnimSFML::listGestAnim;

GestAnimSFML::GestAnimSFML(sf::RenderWindow* window)
{
	GestAnim::initialiserWindow(window);
}

void GestAnimSFML::update(float deltaTime)
{
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++)
	{
		if ((*it)->getState() == EnumGestAnimState::Animating) {
			(*it)->update(deltaTime);
		}
		else if ((*it)->getState() == EnumGestAnimState::Ending) {
			delete (*it);
			GestAnimSFML::listGestAnim.erase(it);
		}
		
	}
}

void GestAnimSFML::addGestAnimation(GestAnim* gestAnim)
{
	GestAnimSFML::listGestAnim.push_back(gestAnim);
}

GestAnim* GestAnimSFML::getGestAnim(int id)
{
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++)
	{
		if ((*it)->getID() == id) {
			return *it;
		}
	}
	return nullptr;
}

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

void GestAnimSFML::DeleteWithId(int id)
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
