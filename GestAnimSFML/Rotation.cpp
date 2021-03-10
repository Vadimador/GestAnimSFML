#include "Rotation.h"

Rotation::Rotation(GestAnimated* objet, float degreePerSecond, bool turnRight)
	:GestAnim(objet), degreePerSecond(degreePerSecond), turnRight(turnRight)
{
}

void Rotation::update(float deltaTime)
{
	if (!this->turnRight) {
		this->objet->setGestRotate(-(this->degreePerSecond * deltaTime));
	}
	else
	{
		this->objet->setGestRotate(this->degreePerSecond * deltaTime);
	}
}

void Rotation::firstStart()
{
}
