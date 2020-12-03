#include "TranslationAnim.h"
#include "cmath"
#include <iostream>


TranslationAnim::TranslationAnim(GestAnimated* object, TranslationType type, sf::Vector2f direction,
	float speed, float time)
	:GestAnim(object), type(type), speed(speed), time(time), remainingTime(time)
{

	//on initialise length par la longueur du vecteur direction, puis on norme direction
	length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	this->direction = sf::Vector2f(direction.x / length, direction.y / length);

}

void TranslationAnim::update(float deltaTime)
{

	//on récupère la position actuelle
	sf::Vector2f position = this->objet->getGestPosition();
	float X = position.x;
	float Y = position.y;




	if (this->type == TranslationType::Speed)
	{
		//le temps de translation est donné par time
		this->time = this->length / this->speed;
		this->remainingTime = time;

		//on change le type de translation en Time, avec lequel les calculs s'effectueront
		this->type = TranslationType::Time;

	}

	if (this->type == TranslationType::Time)
	{
		remainingTime -= deltaTime;

		//si l'on a dépassé le délai restant, on s'arrête
		if (remainingTime <= 0)
		{
			this->setState(EnumGestAnimState::Ending);
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
