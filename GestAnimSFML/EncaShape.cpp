#include "EncaShape.h"

EncaShape::EncaShape(sf::Shape* shape)
    : GestAnimated(true), shape(shape)
{
}

sf::Vector2f EncaShape::getGestSize() const
{
    return sf::Vector2f(this->shape->getGlobalBounds().width, this->shape->getGlobalBounds().height);
}

sf::Vector2f EncaShape::getGestPosition() const
{
    return this->shape->getPosition();
}

sf::Vector2f EncaShape::getGestRotationAxis() const
{
    return this->shape->getOrigin();
}

float EncaShape::getGestRotation() const
{
    return this->shape->getRotation();
}

sf::Color EncaShape::getGestColor() const
{
    return this->shape->getFillColor();
}

void EncaShape::setGestSize(sf::Vector2f size)
{
    this->shape->setScale(sf::Vector2f(this->shape->getGlobalBounds().width * (size.x / this->shape->getGlobalBounds().width ), this->shape->getGlobalBounds().height * (size.y / this->shape->getGlobalBounds().height))); // pas sûr du tout
}

void EncaShape::setGestPosition(sf::Vector2f position)
{
    this->shape->setPosition(position);
}

void EncaShape::setGestRotationAxis(sf::Vector2f posAxis)
{
    this->shape->setOrigin(posAxis);
}

void EncaShape::setGestRotation(float rotation)
{
    this->shape->setRotation(rotation);
}

void EncaShape::setGestColor(sf::Color color)
{
    this->shape->setFillColor(color);
}
