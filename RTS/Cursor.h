#pragma once

#include <Arduboy2.h>

#include "Utils.h"

struct Cursor
{
	static constexpr uint8_t radius = 3;
	static constexpr uint8_t colour = 1;

	Point2F position;
};
