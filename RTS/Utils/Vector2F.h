#pragma once

// For sqrt
#include <math.h>

struct Vector2F
{
	float x;
	float y;

	// This is provided for avoiding the expensive sqrt needed to get the actual magnitude
	float getMagnitudeSquared() const
	{
		return ((this->x * this->x) + (this->y * this->y));
	}

	float getMagnitude() const
	{
		return sqrt(this->getMagnitudeSquared());
	}
};

inline Vector2F normalise(const Vector2F & vector)
{
	const float length = vector.getMagnitude();
	return { (vector.x / length), (vector.y / length) };
}
