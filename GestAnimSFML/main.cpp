#include <iostream>
#include "SFML/Graphics.hpp"
#include "GestAnimSFML.h"
#include "EncaTransformable.h"
#include "EncaShape.h"
#include "SwitchColor.h"
#include "testanim.h"
#include "Clignotement.h"
#include "cheminAnim.h"
#include "transition.h"
#include "TranslationAnim.h"
#include "Rotation.h"

//Test cheminAnim
sf::Vector2f monChemin(float t) {
    return sf::Vector2f(t, 0.2*sin(t* 2*3.14159265358979323846264338327950288419716939937510)); //FORMULE A CHANGER  POUR CHANGER L'ANIMATION
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    GestAnimSFML gAnimSFML = GestAnimSFML(&window); // initialisation
    
    sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
    sf::RectangleShape shape2(sf::Vector2f(50.f, 50.f));

    shape.setPosition(sf::Vector2f(0.f, 0.f));
    shape.setFillColor(sf::Color::Green);

    shape2.setPosition(sf::Vector2f(100.f, 0.f));
    shape2.setFillColor(sf::Color::Red);


    //Test des chaînes d'animation
    //GestAnim* ga = GestAnimSFML::addGestAnimation(new transition(new EncaTransformable(&shape),monChemin,sf::Vector2f(600,300), 0.5f));
    /*ga->nextGestAnimation(new SwitchColor(new EncaShape(&shape), sf::Color::Red, 3.f))
        ->nextGestAnimation(new SwitchColor(new EncaShape(&shape), sf::Color::Blue, 3.f))
        ->nextGestAnimation(new Clignotement(new EncaShape(&shape), 0.3f, sf::Color::Cyan))*/
    //GestAnim* ga = GestAnimSFML::addGestAnimation(new TranslationAnim(new EncaShape(&shape), TranslationTypeSpeed(-1.f, sf::Vector2f(400.f, 400.f), true)));
    //ga->nextGestAnimation(new TranslationAnim(new EncaShape(&shape), TranslationTypeTime(3.f, sf::Vector2f(0.f, 0.f), true)));
    GestAnimSFML::addGestAnimation(new Clignotement(new EncaShape(&shape), 1.f));
    GestAnimSFML::addGestAnimation(new TranslationAnim(new EncaShape(&shape), TranslationTypeTime(3.f, sf::Vector2f(400.f, 400.f), true)));
    GestAnimSFML::addGestAnimation(new TranslationAnim(new EncaShape(&shape2), TranslationTypeTime(10.f, sf::Vector2f(400.f, 0.f), false)));
    GestAnimSFML::addGestAnimation(new Clignotement(new EncaShape(&shape2), 0.2f));
    GestAnimSFML::addGestAnimation(new Rotation(new EncaShape(&shape), 100.f,true));

    bool onetime = true;

    sf::Clock clock;
    float deltaTime = 0.f;


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Update
        GestAnimSFML::update(deltaTime);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onetime) {
            //ga->end();
            onetime = false;
        }
        

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }
    
    return 0;
}

/*
* Translation de A a B direct (selon vitesse ou temps) <-- pour le Fran�ois
* Translation de A a B direct avec rebond
* Translation via fonction <-- pour le nathou (dans l'id�al : funtion("x+2"))
* Changement vers couleur pr�cise <-- pour le Vadim
* Vibration
* Flotement <-- pour le Fran�ois
* Oscillation
* Clignotement <-- pour le Vadim
* Rotation
* ------ R�fl�chir sur les cha�nes d'animations
* Max 30 novembre
*/
