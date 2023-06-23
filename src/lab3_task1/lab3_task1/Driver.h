#pragma once
#include "stdfx.h"
#include "Car.h"

class Driver
{
public:
	Driver(Car& car);

	void Info();
	void EngineOn();
	void EngineOff();
	void SetGear(std::istream& args);
	void SetSpeed(std::istream& args);

private:
	Car m_car;
};