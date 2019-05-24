#pragma once

#include <stdint.h>

#include "Utils.h"

enum class PersonState : uint8_t
{
	Idle,
	Selected,
	Moving,
};

struct Person
{
	static constexpr uint8_t width = 5;
	static constexpr uint8_t height = 5;

	static constexpr float movementSpeed = 1.1f;

	PersonState state;
	Point2F position;

	RectangleF getBounds() const
	{
		return { position.x, position.y, width, height };
	}
};