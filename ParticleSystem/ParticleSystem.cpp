#include "ParticleSystem.h"


void ParticleSystem::update(float dt) {
	if (Keyboard::isKeyPressed(Keyboard::Up) && !upPressed) {
		upPressed = true;
		this->emissionRate += 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) && !downPressed) {
		downPressed = true;
		this->emissionRate -= 1;
	}
	if (!Keyboard::isKeyPressed(Keyboard::Up)) {
		upPressed = false;
	}
	if (!Keyboard::isKeyPressed(Keyboard::Down)) {
		downPressed = false;
	}
	int particleCounter = 0;
	for (int i = 0; i < 10000; i++) {
		if (particles[i]->lifeStatus) {
			particles[i]->update(dt);
		}
		else {
			if (particleCounter < emissionRate) {
				Vector2f size = Vector2f(45, 45);
				particles[i]->resetParticle(emissionPoint, getRandomNumberUpto(4), getRandomNumberUpto(150), Vector2f(randomNumberAroundZero(angleMultiplier), -1), true, texture, size);
				particleCounter++;
			}
		}
	}
}

void ParticleSystem::draw(RenderWindow* window) {
	for (int i = 0; i < 10000; i++) {
		if (particles[i]->lifeStatus) {
			particles[i]->draw(window);
		}
	}
}

ParticleSystem::ParticleSystem(int emissionRate, Vector2f emissionPoint, Texture* texture, float angleMultiplier)
{
	this->emissionRate = emissionRate;
	this->emissionPoint = emissionPoint;
	this->texture = texture;
	this->angleMultiplier = angleMultiplier;
	for (int i=0; i < 10000; i++) {
		Particle* p = new Particle();
		particles[i] = p;
	}
}


ParticleSystem::~ParticleSystem()
{
}

float ParticleSystem::randomNumberAroundZero(float number) {
	return (-number + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (number * 2))));
}

float ParticleSystem::getRandomNumberUpto(float number) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r * number;
}