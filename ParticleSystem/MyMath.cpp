#pragma once
#include "MyMath.h"
using namespace sf;

float Magnitude(Vector2f vector) {
	return sqrtf((vector.x*vector.x) + (vector.y*vector.y));

}

Vector2f Normalize(Vector2f vector) {
	float length = Magnitude(vector);
	if (length == 0) {
		return Vector2f(0, 0);
	}

	vector.x = vector.x / length;
	vector.y = vector.y / length;
	return vector;

}

Vector2f limit(Vector2f vector, float limit) {
	if (Magnitude(vector) > limit) {
		vector = Normalize(vector);
		vector.x *= limit;
		vector.y *= limit;
	}
	return vector;
}

