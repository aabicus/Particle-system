#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "VehicleSystem.h"
#include "MyMath.h"
using namespace sf;

RenderWindow window;
Texture texture1;
Texture texture2;
Texture texture3;
int main()
{
	Clock clock;
	texture1.loadFromFile("flame1.png");
	texture2.loadFromFile("flame2.png");
	texture3.loadFromFile("flame3.png");
	window.create(sf::VideoMode(800, 600), "Particle System");
	VehicleSystem firstSystem(1, Vector2f(400, 300), &texture1, 1);
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		firstSystem.update(dt);
		firstSystem.draw(&window);
		window.display();
	}

	return 0;
}
