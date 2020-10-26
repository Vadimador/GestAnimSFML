#include "EncaTransformable.h"

EncaTransformable::EncaTransformable(sf::Transformable* trans)
	: trans(trans)
{
}

sf::Vector2f EncaTransformable::getGestPosition() const
{
	return this->trans->getPosition();
}

sf::Vector2f EncaTransformable::getGestRotationAxis() const
{
	return this->trans->getOrigin();
}

float EncaTransformable::getGestRotation() const
{
	return this->trans->getRotation();
}

void EncaTransformable::setGestPosition(sf::Vector2f position)
{
	this->trans->setPosition(position);
}

void EncaTransformable::setGestRotationAxis(sf::Vector2f posAxis)
{
	this->trans->setOrigin(posAxis);
}

void EncaTransformable::setGestRotation(float rotation)
{
	this->trans->setRotation(rotation);
}

