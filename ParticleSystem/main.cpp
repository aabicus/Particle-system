#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Particle.h"
#include "ParticleSystem.h"
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
	ParticleSystem firstSystem(1, Vector2f(400, 300), &texture1, 1);
	ParticleSystem secondSystem(4, Vector2f(200, 300), &texture2, 0.5);
	ParticleSystem thirdSystem(8, Vector2f(600, 300), &texture3, 1.5);
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
		secondSystem.update(dt);
		secondSystem.draw(&window);
		thirdSystem.update(dt);
		thirdSystem.draw(&window);
		window.display();
	}

	return 0;
}
