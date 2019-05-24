#pragma once

// For uint8_t
#include <stdint.h>

// For WIDTH and HEIGHT
#include <Arduboy2.h>

// For Point2 and Point2F
#include "Utils.h"

struct Camera
{
	Point2 position;

	uint8_t getWidth() const
	{
		return WIDTH;
	}

	uint8_t getHeight() const
	{
		return HEIGHT;
	}

	Point2 toLocal(const Point2 & globalPoint) const
	{
		return { (globalPoint.x - this->position.x), (globalPoint.y - this->position.y) };
	}

	Point2F toLocal(const Point2F & globalPoint) const
	{
		return { (globalPoint.x - this->position.x), (globalPoint.y - this->position.y) };
	}

	Point2 toGlobal(const Point2 & localPoint) const
	{
		return { (localPoint.x + this->position.x), (localPoint.y + this->position.y) };
	}

	Point2F toGlobal(const Point2F & localPoint) const
	{
		return { (localPoint.x + this->position.x), (localPoint.y + this->position.y) };
	}
};