#pragma once
#include "SFML/Graphics.hpp"

class GestAnimated
{
public:
	virtual sf::Vector2f getGestSize() const = 0;
	virtual sf::Vector2f getGestPosition() const = 0;
	virtual sf::Vector2f getGestRotationAxis() const = 0;
	virtual sf::Vector2f getGestRotation() const = 0;

	virtual sf::Vector2f setGestSize() const = 0;
	virtual sf::Vector2f setGestPosition() const = 0;
	virtual sf::Vector2f setGestRotationAxis() const = 0;
	virtual sf::Vector2f setGestRotation() const = 0;
};

