#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	int pos=0, i=0, n=5;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 600), "jueguito", sf::Style::Default, settings);
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        /*creacion de los enemigos*/
        std::vector<sf::CircleShape> enemies;
        
        for (int i=0; i<5; i++){
          sf::CircleShape shape(50);
          shape.setPosition(700, i*100);
          shape.setFillColor(sf::Color::Red);
          
          enemies.push_back(shape);
        }

        for (std::vector<sf::CircleShape>::iterator enemy = enemies.begin() ; enemy != enemies.end(); ++enemy){
          window.draw(*enemy);
        }
        
        
        window.draw(shape);
        /*display a todo*/
        window.display();
        
        /*movimientos del personaje*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
		    shape.move(0.f, -1.f);
		}
		if (shape.getPosition().y > 600){
			shape.setPosition(0,-100);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
		    shape.move(0.f, 1.f);
		}
		if (shape.getPosition().y < -100){
			shape.setPosition(0,600);
		}
		/*izquierda y derecha*/
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
		    shape.move(-1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
		    shape.move(1.f, 0.f);
		}*/
    }

    return 0;
}
