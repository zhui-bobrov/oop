#include "stdafx.h"
#include "CSolidBody.h"

CSolidBody::CSolidBody(const std::string& shapeType, double density)
    : CBody(shapeType)
    , m_density(density)
{
	if (density <= 0.0)
	{
		throw std::invalid_argument("Invalid density!");
	}
}

double CSolidBody::GetDensity() const
{
	return m_density;
}

double CSolidBody::GetMass() const
{
	return GetVolume() * GetDensity();
}

/*
double CSolidBody::GetWeightInWater() const
{
	return (GetDensity() - WATER_DENSITY) * G * GetVolume();
}
*/