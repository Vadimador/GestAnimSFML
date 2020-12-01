#pragma once
#include "GestAnimated.h"
#include "EnumGestAnimState.h"

class GestAnimSFML;

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
	std::vector<GestAnim*> listNextAnim;
	bool isStarted = false;
public:
	static void initialiserWindow(sf::RenderWindow* window);

	GestAnim(GestAnimated* objet);
	void parentUpdate(float deltaTime);

	virtual void firstStart(); // méthode vide pas obligatoire, à surcharger uniquement si votre GestAnim doit rafraichir ses variables si elle est activée à la chaîne.
	virtual void update(float deltaTime) = 0;

	virtual void end();
	virtual void pause();
	virtual void animate();

	GestAnim* nextGestAnimation(GestAnim* gestAnim);

	int getID();
	EnumGestAnimState getState();

	virtual ~GestAnim();
};

