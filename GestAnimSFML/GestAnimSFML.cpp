#include "GestAnimSFML.h"

std::vector<GestAnim*> GestAnimSFML::listGestAnim;
std::vector<int> GestAnimSFML::listTempUpdateDelete;

GestAnimSFML::GestAnimSFML(sf::RenderWindow* window)
{
	GestAnim::initialiserWindow(window);
}

void GestAnimSFML::update(float deltaTime)
{
	int i = 0;
	for (auto it = GestAnimSFML::listGestAnim.begin(); it != GestAnimSFML::listGestAnim.end(); it++, i++)
	{
		if ((*it)->getState() == EnumGestAnimState::Animating) {
			(*it)->parentUpdate(deltaTime);
		}
		else if ((*it)->getState() == EnumGestAnimState::Ending) {
			GestAnimSFML::listTempUpdateDelete.push_back(i);
		}
		
	}
	
	for (int index = GestAnimSFML::listTempUpdateDelete.size() - 1; index >= 0; index--) // amélioration possible : transformer ce for en for avec iterateur
	{
		delete (*(GestAnimSFML::listGestAnim.begin() + index));
		GestAnimSFML::listGestAnim.erase(GestAnimSFML::listGestAnim.begin() + index);
		GestAnimSFML::listTempUpdateDelete.erase(GestAnimSFML::listTempUpdateDelete.begin() + index);
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
