#pragma once
#include "GestAnim.h"


//enum pour stocker le type de translation (en fonction des informations donn�es en param�tres)
enum class TranslationEnumType
{
	Speed, //la vitesse de la translation est donn�e en param�tre
	Time //la dur�e de la translation est donn�e en param�tre
};

//type donn� en param�tre pour sp�cifier le type de translation
class TranslationType {
public:
	TranslationEnumType te;
};



//Pour une translation o� l'on fournit le temps de trajet
class TranslationTypeTime : public TranslationType {

public:
	//temps de translation
	float time;
	//vecteur directeur OU point d'arriv�e (en fonction de isFinalPoint)
	sf::Vector2f direction;
	bool isFinalPoint;

	TranslationTypeTime(float time, sf::Vector2f direction, bool isFinalPoint) {
		this->te = TranslationEnumType::Time;
		this->time = time;
		this->direction = direction;
		this->isFinalPoint = isFinalPoint;
	}
};



//Pour une translation o� l'on fournit la vitesse de trajet
class TranslationTypeSpeed : public TranslationType {
public:
	//vitesse de translation
	float speed;
	//vecteur directeur OU point d'arriv�e (en fonction de isFinalPoint)
	sf::Vector2f direction;
	bool isFinalPoint;

	TranslationTypeSpeed(float speed, sf::Vector2f direction, bool isFinalPoint) {
		this->te = TranslationEnumType::Speed;
		this->speed = speed;
		this->direction = direction;
		this->isFinalPoint = isFinalPoint;
	}
};

class TranslationAnim : public GestAnim
{

private:

	//bool�en pour d�terminer si les param�tres fournissent le vecteur directeur ou le point d'arriv�e
	//afin d'initialiser correctement "direction"
	bool isFinalPoint;

	//direction de la translation et distance � parcourir (longueur du vecteur)
	sf::Vector2f direction;
	float length = 0.f;

	//type de translation (suivant la vitesse ou le temps)
	TranslationEnumType type;

	//vitesse et d�lai pour l'ex�cution de l'animation
	float speed = 0.f;
	float time = 0.f;

	//combien de secondes reste-t-il avant d'atteindre B ?
	float remainingTime = 0.f;


	sf::Vector2f PointsToVector(sf::Vector2f initial, sf::Vector2f final);

public:
	TranslationAnim(GestAnimated* object, TranslationTypeTime* transType);
	TranslationAnim(GestAnimated* object, TranslationTypeSpeed* transType);
	void update(float deltaTime);
	void firstStart();
};
