#pragma once
#include "GestAnim.h"


//enum pour stocker le type de translation (en fonction des informations données en paramètres)
enum class TranslationEnumType
{
	Speed, //la vitesse de la translation est donnée en paramètre
	Time //la durée de la translation est donnée en paramètre
};

//type donné en paramètre pour spécifier le type de translation
class TranslationType {
public:
	TranslationEnumType te;
};



//Pour une translation où l'on fournit le temps de trajet
class TranslationTypeTime : public TranslationType {

public:
	//temps de translation
	float time;
	//vecteur directeur OU point d'arrivée (en fonction de isFinalPoint)
	sf::Vector2f direction;
	bool isFinalPoint;

	TranslationTypeTime(float time, sf::Vector2f direction, bool isFinalPoint) {
		this->te = TranslationEnumType::Time;
		this->time = time;
		this->direction = direction;
		this->isFinalPoint = isFinalPoint;
	}
};



//Pour une translation où l'on fournit la vitesse de trajet
class TranslationTypeSpeed : public TranslationType {
public:
	//vitesse de translation
	float speed;
	//vecteur directeur OU point d'arrivée (en fonction de isFinalPoint)
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

	//booléen pour déterminer si les paramètres fournissent le vecteur directeur ou le point d'arrivée
	//afin d'initialiser correctement "direction"
	bool isFinalPoint;

	//direction de la translation et distance à parcourir (longueur du vecteur)
	sf::Vector2f direction;
	float length = 0.f;

	//type de translation (suivant la vitesse ou le temps)
	TranslationEnumType type;

	//vitesse et délai pour l'exécution de l'animation
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
