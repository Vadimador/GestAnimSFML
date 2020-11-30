#include <iostream>
#include "SFML/Graphics.hpp"
#include "GestAnimSFML.h"
#include "EncaTransformable.h"
#include "testanim.h"
#include "cheminAnim.h"

//Test cheminAnim
sf::Vector2f monChemin(double t) {
    return sf::Vector2f(100+100*sin(10*t), 100+200*cos(10*t)); //FORMULE A CHANGER  POUR CHANGER L'ANIMATION
};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML works!");
    GestAnimSFML gAnimSFML = GestAnimSFML(&window); // initialisation
    
    sf::RectangleShape shape(sf::Vector2f(100.f, 50.f));

    shape.setPosition(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::Green);

    GestAnimSFML::addGestAnimation(new cheminAnim(new EncaTransformable(&shape),monChemin));

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
        /*shape.rotate(0.05f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            GestAnimSFML::addGestAnimation(new testanim(new EncaTransformable(&shape)));
        }
        
        std::cout << shape.getPosition().x << "," << shape.getPosition().y << "\n";
        */

        window.clear();
        window.draw(shape);
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
