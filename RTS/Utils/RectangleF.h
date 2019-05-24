#pragma once

#include "Point2F.h"
#include "Rectangle.h"

struct RectangleF
{
	float x;
	float y;
	float width;
	float height;

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

	bool contains(const Point2F & point) const
	{
		return ((point.x >= this->getLeft()) && (point.x <= this->getRight()) && (point.y >= this->getTop()) && (point.y <= this->getBottom()));
	}

	bool contains(const RectangleF & rectangle) const
	{
		return (this->contains(Point2F(rectangle.getLeft(), rectangle.getTop())) && this->contains(Point2F(rectangle.getRight(), rectangle.getBottom())));
	}
};

inline bool areIntersecting(const RectangleF & rectangle0, const RectangleF & rectangle1)
{
	return
	!(
		(rectangle1.getLeft() >= rectangle0.getRight()) ||
		(rectangle1.getRight() <= rectangle0.getLeft()) ||
		(rectangle1.getTop() >= rectangle0.getBottom()) ||
		(rectangle1.getBottom() <= rectangle0.getTop())
	);
}

inline bool areIntersecting(const RectangleF & rectangle0, const Rectangle & rectangle1)
{
	return
	!(
		(rectangle1.getLeft() >= rectangle0.getRight()) ||
		(rectangle1.getRight() <= rectangle0.getLeft()) ||
		(rectangle1.getTop() >= rectangle0.getBottom()) ||
		(rectangle1.getBottom() <= rectangle0.getTop())
	);
}

inline bool areIntersecting(const Rectangle & rectangle0, const RectangleF & rectangle1)
{
	return areIntersecting(rectangle1, rectangle0);
}