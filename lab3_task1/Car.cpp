#include <iostream>
#include <string>

#include "Car.h"

using namespace std;

class Car
{
private:
	bool engineOn;
	int currentGear;
	int currentSpeed;
	string direction;

public:
	bool turnOnEngine()
	{
		if (!engineOn)
		{
			engineOn = true;
			currentGear = 0;
			currentSpeed = 0;
		}
		return true;
	}

	bool turnOffEngine()
	{
		if (currentGear == 0 && currentSpeed == 0)
		{
			engineOn = false;
			return true;
		}
		return false;
	}

	bool setGear(int newGear)
	{
		if (engineOn && isValidSpeed(newGear, currentSpeed))
		{
			currentGear = newGear;
			return true;
		}
		return false;
	}

	bool setSpeed(int newSpeed)
	{
		if (engineOn)
		{
			if (currentGear == 0 && newSpeed < currentSpeed)
			{
				currentSpeed = newSpeed;
				return true;
			}
			else if (currentGear != 0 && isValidSpeed(currentGear, newSpeed))
			{
				currentSpeed = newSpeed;
				return true;
			}
		}
		return false;
	}

	bool getEngineStatus()
	{
		return engineOn;
	}

	int getCurrentSpeed()
	{
		return currentSpeed;
	}

	int getCurrentGear()
	{
		return currentGear;
	}

	string getDirection()
	{
		string direction;

		if (currentSpeed == 0)
		{
			direction = "stand";
		}
		else if (currentGear == -1)
		{
			direction = "back";
		}
		else
		{
			direction = "forward";
		}
		return direction;
	}

	void info()
	{
		std::cout << "Состояние автомобиля:" << std::endl;
		std::cout << "Двигатель: " << (getEngineStatus() ? "включен" : "выключен") << std::endl;
		std::cout << "Передача: " << getCurrentGear() << std::endl;
		std::cout << "Скорость: " << getCurrentSpeed() << " км/ч" << std::endl;
		std::cout << "Направление: " << getDirection() << std::endl;
	}

private:
	bool isValidSpeed(int gear, int speed)
	{
		switch (gear)
		{
		case -1:
			return (speed >= 0 && speed <= 20);
		case 0:
			return true;
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
};