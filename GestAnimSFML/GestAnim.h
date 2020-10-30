#pragma once
#include "GestAnimated.h"
#include "EnumGestAnimState.h"

class GestAnim
{
private:
	EnumGestAnimState state;
	static int IdCompteur;
	int id;
	
	
protected:
	GestAnimated* objet;
	static sf::RenderWindow* window;
	sf::Vector2u getSizeWindow();
	void setState(EnumGestAnimState&& state);
public:
	static void initialiserWindow(sf::RenderWindow* window);

	GestAnim(GestAnimated* objet);

	virtual void update(float deltaTime) = 0;
	virtual void stop();

	int getID();
	EnumGestAnimState getState();

	virtual ~GestAnim();
};

