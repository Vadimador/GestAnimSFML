#pragma once
#include "SFML/Graphics.hpp"

class GestAnimated
{
public:
	virtual sf::Vector2f getGestSize() const;
	virtual sf::Vector2f getGestPosition() const ;
	virtual sf::Vector2f getGestRotationAxis() const;
	virtual float getGestRotation() const;
	virtual sf::Color getGestColor() const;

	virtual void setGestSize(sf::Vector2f size);
	virtual void setGestPosition(sf::Vector2f position);
	virtual void setGestRotationAxis(sf::Vector2f posAxis) ;
	virtual void setGestRotation(float rotation);
	virtual void setGestColor(sf::Color color);
};

