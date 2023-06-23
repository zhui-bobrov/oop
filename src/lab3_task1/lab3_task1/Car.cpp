#include "Car.h"

Car::Car()
	: m_engineOn(false)
	, m_currentGear(0)
	, m_currentSpeed(0)
{
}

bool Car::TurnOnEngine()
{
	if (!m_engineOn)
	{
		m_engineOn = true;
	}
	return true;
}

bool Car::TurnOffEngine()
{
	if (m_currentGear == 0 && m_currentSpeed == 0)
	{
		m_engineOn = false;
		return true;
	}
	return false;
}

bool Car::SetGear(int newGear)
{
	if (m_engineOn && IsValidGear(newGear) && IsValidSpeed(newGear, m_currentSpeed))
	{
		m_currentGear = newGear;
		return true;
	}
	return false;
}

bool Car::SetSpeed(int newSpeed)
{
	if (!m_engineOn || newSpeed < 0)
	{
		return false;
	}

	if (m_currentGear == -1 || m_currentSpeed < 0)
	{
		newSpeed = newSpeed * -1;
	}

	if (m_currentGear == 0 && abs(newSpeed) < abs(m_currentSpeed))
	{
		m_currentSpeed = newSpeed;
		return true;
	}
	else if (m_currentGear != 0 && IsValidSpeed(m_currentGear, newSpeed))
	{
		m_currentSpeed = newSpeed;
		return true;
	}

	return false;
}

bool Car::GetEngineStatus() const
{
	return m_engineOn;
}

int Car::GetCurrentSpeed() const
{
	return abs(m_currentSpeed);
}

int Car::GetCurrentGear() const
{
	return m_currentGear;
}

Direction Car::GetDirection() const
{
	if (m_currentSpeed < 0)
	{
		return Direction::Back;
	}
	else if (m_currentSpeed > 0)
	{
		return Direction::Forward;
	}
	else
	{
		return Direction::Stand;
	}
}

std::string Car::DirectionToString() const
{
	Direction currentDirection = GetDirection();

	if (currentDirection == Direction::Forward)
	{
		return "Forward";
	}

	if (currentDirection == Direction::Back)
	{
		return "Back";
	}

	if (currentDirection == Direction::Stand)
	{
		return "Stand";
	}
}

bool Car::IsValidSpeed(int gear, int speed)
{
	switch (gear)
	{
	case -1:
		return (speed >= -20 && speed <= 0);
	case 0:
		return (abs(speed) <= abs(m_currentSpeed));
	case 1:
		return (speed >= 0 && speed <= 30);
	case 2:
		return (speed >= 20 && speed <= 50);
	case 3:
		return (speed >= 30 && speed <= 60);
	case 4:
		return (speed >= 40 && speed <= 90);
	case 5:
		return (speed >= 50 && speed <= 150);
	default:
		return false;
	}
}

bool Car::IsValidGear(int newGear)
{
	if (m_currentGear < 0 && newGear > 0 && m_currentSpeed != 0)
	{
		return false;
	}
	else if (m_currentGear > 0 && newGear < 0 && m_currentSpeed != 0)
	{
		return false;
	}
	return true;
}