#pragma once
#include "GestAnim.h"


//translation rectiligne uniforme



enum class TranslationType
{
	Speed, //la vitesse de la translation est donnée en paramètre
	Time //la durée de la translation est donnée en paramètre
};

class TranslationAnim : public GestAnim
{

private:

	//direction de la translation et distance à parcourir (longueur du vecteur)
	sf::Vector2f direction;
	float length;

	//type de translation (suivant la vitesse ou le temps)
	TranslationType type;

	//vitesse et délai pour l'exécution de l'animation
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

