#include "Driver.h"

Driver::Driver(Car& car)
	: m_car(car)
{
}

void Driver::Info()
{
	std::cout << "Engine: " << (m_car.GetEngineStatus() ? "On" : "Off") << std::endl;
	std::cout << "Gear: " << m_car.GetCurrentGear() << std::endl;
	std::cout << "Speed: " << m_car.GetCurrentSpeed() << " km/h" << std::endl;
	std::cout << "Direction: " << m_car.DirectionToString() << std::endl;
}

void Driver::EngineOn()
{
	if (m_car.TurnOnEngine())
	{
		std::cout << "-- Brrrrr." << std::endl;
	}
	else
	{
		std::cout << "-- Nothing happened." << std::endl;
	}
}

void Driver::EngineOff()
{
	if (m_car.TurnOffEngine())
	{
		std::cout << "-- Engire is off." << std::endl;
	}
	else
	{
		std::cout << "-- Nothing happened." << std::endl;
	}
}

void Driver::SetGear(std::istream& args)
{
	int gear;
	args >> gear;

	if (m_car.SetGear(gear))
	{
		std::cout << "-- Gear is setted." << std::endl;
	}
	else
	{
		std::cout << "-- Khhh." << std::endl;
	}
}

void Driver::SetSpeed(std::istream& args)
{
	int speed;
	args >> speed;

	if (m_car.SetSpeed(speed))
	{
		std::cout << "-- Speed is setted." << std::endl;
	}
	else
	{
		std::cout << "-- Nothing happened." << std::endl;
	}
}