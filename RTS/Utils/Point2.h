#pragma once

// For int16_t
#include <stdint.h>

struct Point2
{
	int16_t x;
	int16_t y;

	Point2() = default;

	constexpr Point2(int16_t x, int16_t y) :
		x {x}, y {y}
	{
	}
};