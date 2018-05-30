#include "VehicleSystem.h"
#include "MyMath.h"



void Vehicle::resetParticle(Vector2f position, float lifetime, float speed, Vector2f direction, bool lifeStatus, Texture* texture, Vector2f originalSize)
{
	shape.setPointCount(3);
	shape.setPoint(0, Vector2f(0, 0));
	shape.setPoint(1, Vector2f(20, 10));
	shape.setPoint(2, Vector2f(0, 20));
	shape.setOrigin(originalSize.x / 2, originalSize.y / 2);
	shape.setPosition(position);
	shape.setTexture(texture);
	shape.setRotation(getRandomNumberUpto(360));
	shape.setFillColor(Color::Red);
}

Vehicle::Vehicle(VehicleSystem* newVS, Vector2f pos)
{
	vs = newVS;
	shape.setPointCount(3);
	shape.setPoint(0, Vector2f(0, 0));
	shape.setPoint(1, Vector2f(20, 10));
	shape.setPoint(2, Vector2f(0, 20));
	position = pos;
	shape.setPosition(pos);
	shape.setFillColor(Color::Red);
}


Vehicle::~Vehicle()
{
}

void Vehicle::draw(RenderWindow * window)
{
	window->draw(shape);
}

void Vehicle::update(float dt)
{
	ApplyForce(computeSeparation());
	ApplyForce(computeCohesion());
		velocity += acceleration*dt;
		limit(velocity, speed);
		position += velocity*dt;
		acceleration = Vector2f(0,0);
		shape.setPosition(position);
}

Vector2f Vehicle::computeSeparation(){
	Vector2f desiredVelocity;
		float count = 0;
		for (int i = 0; i < 100; i++) {
			Vehicle* current = vs->particles[i];
			if (current == this) {
				continue;
			}
			float d = Magnitude(position - current->position);
			if (d < radius) {
				desiredVelocity += Normalize(position - current->position);
				count++;
			}
		}
		if (count == 0) {
			return Vector2f(0, 0);
		}
		desiredVelocity = desiredVelocity / count;
		desiredVelocity = Normalize(desiredVelocity);
		desiredVelocity *= speed;
		Vector2f steer = desiredVelocity - velocity;
		limit(steer, maxForce);
		return steer;
}

Vector2f Vehicle::computeCohesion() {
	Vector2f desiredVelocity;
	float count = 0;
	for (int i = 0; i < 100; i++) {
		Vehicle* current = vs->particles[i];
		if (current == this) {
			continue;
		}
		float d = Magnitude(position - current->position);
		if (d < radius) {
			desiredVelocity += current->position;
			count++;
		}
	}
	if (count == 0) {
		return Vector2f(0, 0);
	}
	desiredVelocity = desiredVelocity / count;
	desiredVelocity = Normalize(desiredVelocity);
	desiredVelocity *= speed;
	Vector2f steer = desiredVelocity - velocity;
	limit(steer, maxForce);
	return steer;
}

void Vehicle::ApplyForce(Vector2f force) {
	acceleration += force;
};


float Vehicle::getRandomNumberUpto(float number) {
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r * number;
}