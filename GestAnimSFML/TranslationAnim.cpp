#include "TranslationAnim.h"
#include "cmath"
#include <iostream>



TranslationAnim::TranslationAnim(GestAnimated* object, TranslationTypeTime* transType)
	:GestAnim(object), isFinalPoint(transType->isFinalPoint), type(transType->te), direction(transType->direction),
	time(transType->time), remainingTime(time)
{
	//direction doit être modifié au lancement de l'animation, en fonction de isFinalPoint notamment
	//Ceci est effectué dans firstStart
}



TranslationAnim::TranslationAnim(GestAnimated* object, TranslationTypeSpeed* transType)
	: GestAnim(object), isFinalPoint(transType->isFinalPoint), type(transType->te), direction(transType->direction), 
	speed(transType->speed)
{
	//direction doit être modifié au lancement de l'animation, en fonction de isFinalPoint notamment
	//Ceci est effectué dans firstStart
}

//A partir de A et de B, renvoit le vecteur AB
sf::Vector2f TranslationAnim::PointsToVector(sf::Vector2f initial, sf::Vector2f final)
{
	return sf::Vector2f(final.x - initial.x, final.y - initial.y);
}

void TranslationAnim::update(float deltaTime)
{

	//on récupère la position actuelle
	sf::Vector2f position = this->objet->getGestPosition();
	float X = position.x;
	float Y = position.y;



	//Test théoriquement inutile : le type de translation a été converti à Time dans le constructeur
	//Il est laissé intact par mesure de sécurité
	if (this->type == TranslationEnumType::Speed)
	{
		//le temps de translation est donné par time
		this->time = this->length / this->speed;
		this->remainingTime = time;

		//on change le type de translation en Time, avec lequel les calculs s'effectueront
		this->type = TranslationEnumType::Time;

	}

	//Test théoriquement inutile : le type de translation a été converti à Time dans le constructeur
	//Il est laissé intact par mesure de sécurité
	if (this->type == TranslationEnumType::Time)
	{
		remainingTime -= deltaTime;

		//si l'on a dépassé le délai restant, on s'arrête
		if (remainingTime <= 0)
		{
			this->end();
		}
		//sinon, on regarde la proportion p de chemin à parcourir
		else
		{
			float p = deltaTime / (this->time);

			//la distance parcourue pendant deltaTime est deltaD
			float deltaD = p * this->length;


			//on met à jour la position
			this->objet->setGestPosition(sf::Vector2f(X + direction.x * deltaD, Y + direction.y * deltaD));
		}
	}
}

void TranslationAnim::firstStart()
{
	//suivant isFinalPoint, il faut ou non calculer le vecteur directeur
	if (isFinalPoint) {
		sf::Vector2f position = this->objet->getGestPosition();
		this->direction = PointsToVector(position, this->direction);
	}


	//on initialise length par la longueur du vecteur direction, puis on norme direction
	length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	this->direction = sf::Vector2f(direction.x / length, direction.y / length);


	/*Les calculs seront effectués grâce au temps plutôt qu'avec la vitesse*/
	/*On convertit donc les informations en leurs équivalents temporels*/
	if (this->type == TranslationEnumType::Speed) {


		//le temps de translation est donné par time
		this->time = this->length / this->speed;
		this->remainingTime = time;

		//on change le type de translation en Time, pour rester cohérent
		this->type = TranslationEnumType::Time;

	}

}
