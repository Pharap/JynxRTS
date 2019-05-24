#pragma once

// For int16_t and uint8_t
#include <stdint.h>

// For min and max
#include <Arduino.h>

#include "Point2.h"

struct Rectangle
{
	int16_t x;
	int16_t y;
	uint8_t width;
	uint8_t height;

	int16_t getLeft() const
	{
		return this->x;
	}

	int16_t getTop() const
	{
		return this->y;
	}

	int16_t getRight() const
	{
		return (this->x + this->width);
	}

	int16_t getBottom() const
	{
		return (this->y + this->height);
	}

	bool contains(const Point2 & point) const
	{
		return ((point.x >= this->getLeft()) && (point.x <= this->getRight()) && (point.y >= this->getTop()) && (point.y <= this->getBottom()));
	}

	bool contains(const Rectangle & rectangle) const
	{
		return (this->contains(Point2(rectangle.getLeft(), rectangle.getTop())) && this->contains(Point2(rectangle.getRight(), rectangle.getBottom())));
	}

	static Rectangle fromPoints(int16_t x0, int16_t y0, int16_t x1, int16_t y1)
	{
		const int16_t startX = min(x0, x1);
		const int16_t startY = min(y0, y1);
		const int16_t endX = max(x0, x1);
		const int16_t endY = max(y0, y1);

		return { startX, startY, static_cast<uint8_t>(endX - startX), static_cast<uint8_t>(endY - startY) };
	}
};

bool areIntersecting(const Rectangle & rectangle0, const Rectangle & rectangle1)
{
	return
	!(
		(rectangle1.getLeft() >= rectangle0.getRight()) ||
		(rectangle1.getRight() <= rectangle0.getLeft()) ||
		(rectangle1.getTop() >= rectangle0.getBottom()) ||
		(rectangle1.getBottom() <= rectangle0.getTop())
	);
}