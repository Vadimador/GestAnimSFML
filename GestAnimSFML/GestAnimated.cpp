#include "GestAnimated.h"

GestAnimated::GestAnimated(bool isEncapsulator)
{
    this->isEncapsulator = isEncapsulator;
}

sf::Vector2f GestAnimated::getGestSize() const
{
    return sf::Vector2f();
}

sf::Vector2f GestAnimated::getGestPosition() const
{
    return sf::Vector2f();
}

sf::Vector2f GestAnimated::getGestRotationAxis() const
{
    return sf::Vector2f();
}

float GestAnimated::getGestRotation() const
{
    return 0.f;
}

sf::Color GestAnimated::getGestColor() const
{
    return sf::Color();
}

void GestAnimated::setGestSize(sf::Vector2f size)
{
}

void GestAnimated::setGestPosition(sf::Vector2f position)
{
}

void GestAnimated::setGestRotationAxis(sf::Vector2f posAxis)
{
}

void GestAnimated::setGestRotation(float rotation)
{
}

void GestAnimated::setGestRotate(float rotation)
{
}

void GestAnimated::setGestColor(sf::Color color)
{
}

bool GestAnimated::IsEncapsulator()
{
    return this->isEncapsulator;
}
