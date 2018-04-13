#include "Particle.h"



void Particle::resetParticle(Vector2f position, float lifetime, float speed, Vector2f direction, bool lifeStatus, Texture* texture, Vector2f originalSize)
{
	
	shape.setSize(originalSize);
	shape.setOrigin(originalSize.x / 2, originalSize.y / 2);
	shape.setPosition(position);
	shape.setTexture(texture);
	shape.setRotation(getRandomNumberUpto(360));
	shape.setFillColor(Color::Red);
	this->originalSize = originalSize;
	this->lifetime = lifetime;
	this->speed = speed;
	this->direction = direction;
	this->lifeStatus = lifeStatus;
	this->maxLife = lifetime;
}

Particle::Particle()
{
}


Particle::~Particle()
{
}

void Particle::draw(RenderWindow * window)
{
	if (lifeStatus) { window->draw(shape); }
	else {}
}

void Particle::update(float dt)
{
	lifetime = lifetime - dt;
	if (lifetime <= 0) {
		lifeStatus = false;
	}
	float lifeRatio = lifetime/maxLife;
	Vector2f oldPosition = shape.getPosition();
	Vector2f newPosition = oldPosition + speed*direction*dt*lifeRatio;
	shape.setPosition(newPosition);
	Color color = shape.getFillColor();
	color.a = lifeRatio * 255;
	color.b = (1 - lifeRatio) * 255;
	shape.setFillColor(color);
	float rotation = shape.getRotation();
	shape.setRotation(rotation + getRandomNumberUpto(150)*dt);
	Vector2f newSize = originalSize*lifeRatio;
	shape.setSize(newSize);
	shape.setOrigin(newSize.x / 2, newSize.y / 2);
}

float Particle::getRandomNumberUpto(float number) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r * number;
}