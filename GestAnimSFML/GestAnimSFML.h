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

	//----------------------------------------------- Fonction de gestion
	static GestAnim* addGestAnimation(GestAnim* gestAnim); // ajoute une animation et la retourne
	
	static void pauseGestAnimation(GestAnim* gestAnim); // met en pause une animation

	static void continueGestAnimation(GestAnim* gestAnim); // continue l'animation de l'animation (hihi)

	static void Delete(GestAnim* gestAnim); // supprime l'animation de la liste d'animation
	static void Delete(int id); // supprime l'animation de la liste d'animation

	~GestAnimSFML();
};

