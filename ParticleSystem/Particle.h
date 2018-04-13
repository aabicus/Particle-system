#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
using namespace sf;

class Particle
{
public:
	Particle(); 
	~Particle();

	RectangleShape shape;
	float lifetime;
	float speed;
	bool lifeStatus = false;
	Vector2f direction;
	float maxLife;
	Vector2f originalSize;

	void update(float dt);
	void draw(RenderWindow* window);
	float getRandomNumberUpto(float number);
	void resetParticle(Vector2f position, float lifetime, float speed, Vector2f direction, bool lifeStatus, Texture* texture, Vector2f originalSize);
};

