#pragma once
#include "GestAnimated.h"
class EncaShape :
    public GestAnimated
{
private:
    sf::Shape* shape;
public:

	EncaShape(sf::Shape* shape);

	sf::Vector2f getGestSize() const;
	sf::Vector2f getGestPosition() const;
	sf::Vector2f getGestRotationAxis() const;
	float getGestRotation() const;
	sf::Color getGestColor() const;

	void setGestSize(sf::Vector2f size);
	void setGestPosition(sf::Vector2f position);
	void setGestRotationAxis(sf::Vector2f posAxis);
	void setGestRotation(float rotation);
	void setGestColor(sf::Color color);
};

