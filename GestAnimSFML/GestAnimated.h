#pragma once
#include "SFML/Graphics.hpp"

class GestAnimated
{
public:
	virtual sf::Vector2f getGestSize() const = 0;
	virtual sf::Vector2f getGestPosition() const = 0;
};

