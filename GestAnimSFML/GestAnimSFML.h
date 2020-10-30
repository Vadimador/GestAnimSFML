#pragma once
#include <iostream>
#include <vector>
#include "GestAnim.h"

class GestAnimSFML
{
private:
	static std::vector<GestAnim*> listGestAnim;
	static std::vector<int> listTempUpdateDelete;

public:
	GestAnimSFML(sf::RenderWindow* window);
	static void update(float deltaTime);
	static void addGestAnimation(GestAnim* gestAnim);

	static GestAnim* getGestAnim(int id);

	static void Delete(GestAnim* gestAnim);
	static void DeleteWithId(int id);

	~GestAnimSFML();
};

