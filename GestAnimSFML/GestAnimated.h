#pragma once
#include "SFML/Graphics.hpp"

class GestAnimated
{
private:
	bool isEncapsulator; // Boolean indiquant si la classe est une classe d'encapsulation ou non (Si true, la classe va être supprimée)
public:
	GestAnimated(bool isEncapsulator);

	virtual sf::Vector2f getGestSize() const;
	virtual sf::Vector2f getGestPosition() const ;
	virtual sf::Vector2f getGestRotationAxis() const;
	virtual float getGestRotation() const;
	virtual sf::Color getGestColor() const;

	virtual void setGestSize(sf::Vector2f size);
	virtual void setGestPosition(sf::Vector2f position);
	virtual void setGestRotationAxis(sf::Vector2f posAxis) ;
	virtual void setGestRotation(float rotation); // rotation général un (défini le degree de la rotation)
	virtual void setGestRotate(float rotation); // rotation dynamique (ajoute le nombre donnée au degrée de la rotation actuel)
	virtual void setGestColor(sf::Color color);

	bool IsEncapsulator();
};

