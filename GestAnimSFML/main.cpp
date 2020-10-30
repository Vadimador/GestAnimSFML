#include <iostream>
#include "SFML/Graphics.hpp"
#include "GestAnimSFML.h"
#include "EncaTransformable.h"
#include "testanim.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML works!");
    GestAnimSFML::GestAnimSFML(&window); // initialisation

    sf::RectangleShape shape(sf::Vector2f(100.f,50.f));
    shape.setPosition(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::Green);

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
        shape.rotate(0.05f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            GestAnimSFML::addGestAnimation(new testanim(&EncaTransformable(&shape)));
        }
        
        std::cout << shape.getPosition().x << "," << shape.getPosition().y << "\n";
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
