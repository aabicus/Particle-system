#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "MyMath.h"
using namespace sf;

class Vehicle;
class VehicleSystem
{
public:
	VehicleSystem(int emissionRate, Vector2f emissionPoint, Texture* texture, float angleMultiplier);
	Vehicle* particles[10000];
	void update(float dt);
	void draw(RenderWindow* window);
	int emissionRate;
	~VehicleSystem();
	Vector2f emissionPoint;
	float randomNumberAroundZero(float number);
	float getRandomNumberUpto(float number);
	Texture* texture;
	float angleMultiplier;
	bool upPressed = false;
	bool downPressed = false;
};

class Vehicle
{
public:
	Vehicle(VehicleSystem*, Vector2f);
	~Vehicle();
	VehicleSystem* vs;
	ConvexShape shape;
	float lifetime;
	float speed=350;
	bool lifeStatus = false;
	Vector2f direction;
	float maxLife;
	Vector2f originalSize;
	Vector2f velocity = Vector2f(0, 0);
	Vector2f acceleration = Vector2f(0, 0);
	Vector2f position=Vector2f(100,100);
	float radius=50;
	float maxForce=300;
	void ApplyForce(Vector2f force);
	void update(float dt);
	void draw(RenderWindow* window);
	float getRandomNumberUpto(float number);
	void resetParticle(Vector2f position, float lifetime, float speed, Vector2f direction, bool lifeStatus, Texture* texture, Vector2f originalSize);
	Vector2f computeSeparation();
	Vector2f computeCohesion();
};