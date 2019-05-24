#pragma once

#include <stdint.h>

#include "Utils.h"

enum class ResourceState : uint8_t
{
	Active,
	Inactive
};

struct Resource
{
	static constexpr uint8_t width = 16;
	static constexpr uint8_t height = 16;
	static constexpr uint8_t defaultRegenenerationDelay = 10;

	ResourceState state;
	Point2 position;
	uint8_t regenerationDelay;
	
	Rectangle getBounds() const
	{
		return { position.x, position.y, width, height };
	}

	void harvest()
	{
		this->state = ResourceState::Inactive;
		this->regenerationDelay = defaultRegenenerationDelay;
	}
};