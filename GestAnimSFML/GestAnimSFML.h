#pragma once
#include <iostream>
#include <vector>
#include "GestAnim.h"

class GestAnimSFML
{
private:
	static std::vector<GestAnim*> listGestAnim;
public:
	static void update(float deltaTime);
	static void addGestAnimation(GestAnim* gestAnim);
};

