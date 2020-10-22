#pragma once
#include "GestAnimated.h"

class GestAnim
{
private:
	GestAnimated* objet;
public:
	GestAnim(GestAnimated* objet);
	virtual void update(float deltaTime) = 0;
};

