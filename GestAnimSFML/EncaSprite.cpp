#include "EncaSprite.h"

EncaSprite::EncaSprite(sf::Sprite* sprite)
    :GestAnimated(true)
{
    this->sprite = sprite;
}

sf::Vector2f EncaSprite::getGestSize() const
{
    return sf::Vector2f(this->sprite->getGlobalBounds().width, this->sprite->getGlobalBounds().height);
}

sf::Vector2f EncaSprite::getGestPosition() const
{
    return this->sprite->getPosition();
}

sf::Vector2f EncaSprite::getGestRotationAxis() const
{
    return this->sprite->getOrigin();
}

float EncaSprite::getGestRotation() const
{
    return this->sprite->getRotation();
}

sf::Color EncaSprite::getGestColor() const
{
    return this->sprite->getColor();
}

void EncaSprite::setGestSize(sf::Vector2f size)
{
    this->sprite->setScale(sf::Vector2f((size.x / this->getGestSize().x), (size.y / this->getGestSize().y)));
}

void EncaSprite::setGestPosition(sf::Vector2f position)
{
    this->sprite->setPosition(position);
}

void EncaSprite::setGestRotationAxis(sf::Vector2f posAxis)
{
    this->sprite->setOrigin(posAxis);
}

void EncaSprite::setGestRotation(float rotation)
{
    this->sprite->setRotation(rotation);
}

void EncaSprite::setGestRotate(float rotation)
{
    this->sprite->rotate(rotation);
}

void EncaSprite::setGestColor(sf::Color color)
{
    this->sprite->setColor(color);
}
