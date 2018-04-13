#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "Particle.h"
using namespace sf;

class ParticleSystem
{
public:
	ParticleSystem(int emissionRate, Vector2f emissionPoint, Texture* texture, float angleMultiplier);
	Particle* particles[10000];
	void update(float dt);
	void draw(RenderWindow* window);
	int emissionRate;
	~ParticleSystem();
	Vector2f emissionPoint;
	float randomNumberAroundZero(float number);
	float getRandomNumberUpto(float number);
	Texture* texture;
	float angleMultiplier;
	bool upPressed = false;
	bool downPressed = false;
};

