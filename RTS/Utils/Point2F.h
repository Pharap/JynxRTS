#pragma once

#include "Vector2F.h"

struct Point2F
{
	float x;
	float y;

	Point2F() = default;

	constexpr Point2F(float x, float y) :
		x {x}, y {y}
	{
	}
};

Vector2F vectorBetween(Point2F point0, Point2F point1)
{
	return { (point1.x - point0.x), (point1.y - point0.y) };
}

float distance(Point2F point0, Point2F point1)
{
	// The distance between two points is the magnitude of the vector between them
	return vectorBetween(point0, point1).getMagnitude();
}

// This is a cheap alternative for when exact distance isn't needed.
// E.g. when comparing two distances
float distanceSquared(Point2F point0, Point2F point1)
{
	// The square distance between two points is the square magnitude of the vector between them
	return vectorBetween(point0, point1).getMagnitudeSquared();
}