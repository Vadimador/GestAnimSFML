#pragma once
#include "GestAnim.h"

class testanim :
	public GestAnim
{
public:
	testanim(GestAnimated* objet);
	void update(float deltaTime);
};

