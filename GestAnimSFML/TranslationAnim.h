#pragma once
#include "GestAnim.h"


//translation rectiligne uniforme



enum class TranslationType
{
	Speed, //la vitesse de la translation est donn�e en param�tre
	Time //la dur�e de la translation est donn�e en param�tre
};

class TranslationAnim : public GestAnim
{

private:

	//direction de la translation et distance � parcourir (longueur du vecteur)
	sf::Vector2f direction;
	float length;

	//type de translation (suivant la vitesse ou le temps)
	TranslationType type;

	//vitesse et d�lai pour l'ex�cution de l'animation
	float speed;
	float time;

	//combien de secondes reste-t-il avant d'atteindre B ?
	float remainingTime;


public:
	//changer : objet, point, et float ou double en fonction de speed ou time
	TranslationAnim(GestAnimated* objet, TranslationType type, sf::Vector2f direction,
		float speed = 0.0, float time = 0.0);
	void update(float deltaTime);
};

