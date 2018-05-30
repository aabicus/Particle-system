#include "VehicleSystem.h"
#include "MyMath.h"


void VehicleSystem::update(float dt) {
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
	for (int i = 0; i < 100; i++) {
		particles[i]->update(dt);
	}
}

void VehicleSystem::draw(RenderWindow* window) {
	for (int i = 0; i < 100; i++) {
			particles[i]->draw(window);
		}
	}

VehicleSystem::VehicleSystem(int emissionRate, Vector2f emissionPoint, Texture* texture, float angleMultiplier)
{
	for (int i=0; i < 100; i++) {
		Vehicle* p = new Vehicle(this, Vector2f(100+ i*10, 100 + i * 10));
		particles[i] = p;
	}
}


VehicleSystem::~VehicleSystem()
{
}

float VehicleSystem::randomNumberAroundZero(float number) {
	return (-number + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (number * 2))));
}

float VehicleSystem::getRandomNumberUpto(float number) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r * number;
}