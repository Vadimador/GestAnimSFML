#pragma once
#include "GestAnimated.h"
class EncaTransformable :
    public GestAnimated
{
private:
    sf::Transformable* trans;
public:
    EncaTransformable(sf::Transformable* trans);

    sf::Vector2f getGestPosition() const;
    sf::Vector2f getGestRotationAxis() const;
    float getGestRotation() const;

    void setGestPosition(sf::Vector2f position);
    void setGestRotationAxis(sf::Vector2f posAxis);
    void setGestRotation(float rotation);
};

