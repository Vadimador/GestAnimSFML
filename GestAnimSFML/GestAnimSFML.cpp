#include "GestAnimSFML.h"

std::vector<GestAnim*> GestAnimSFML::listGestAnim;

void GestAnimSFML::update(float deltaTime)
{
	for (auto animGest : GestAnimSFML::listGestAnim)
	{
		animGest->update(deltaTime);
	}
}

void GestAnimSFML::addGestAnimation(GestAnim* gestAnim)
{
	GestAnimSFML::listGestAnim.push_back(gestAnim);
}
