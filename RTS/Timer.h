#pragma once

#include <Arduino.h>

struct Timer
{
	unsigned long currentMillis = 0;
	unsigned long previousMillis = 0;

	unsigned long getElapsedTime() const
	{
		return (this->currentMillis - this->previousMillis);
	}

	void updatePreviousTime()
	{
		this->previousMillis = this->currentMillis;
	}

	void updateCurrentTime()
	{
		this->currentMillis = millis();
	}
};