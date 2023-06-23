#pragma once
#include "stdfx.h"

enum class Direction
{
	Forward,
	Back,
	Stand
};

class Car
{
public:
	Car();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int newGear);
	bool SetSpeed(int newSpeed);
	bool GetEngineStatus() const;
	int GetCurrentSpeed() const;
	int GetCurrentGear() const;
	Direction GetDirection() const;
	std::string DirectionToString() const;

private:
	bool m_engineOn;
	int m_currentGear;
	int m_currentSpeed;

	bool IsValidSpeed(int gear, int speed);
	bool IsValidGear(int gear);
};