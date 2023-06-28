#include "stdafx.h"
#include "CCylinder.h"

CCylinder::CCylinder(double density, double radius, double height)
	: CSolidBody("Cylinder", density)
	, m_radius(radius)
	, m_height(height)
{
	if (radius <= 0.0)
	{
		throw std::invalid_argument("Invalid radius!");
	}

	if (height <= 0.0)
	{
		throw std::invalid_argument("Invalid height!");
	}
}

double CCylinder::GetVolume() const
{
	return PI * std::pow(m_radius, 2) * m_height;
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

std::string CCylinder::GetAdditionalParameters() const
{
	std::ostringstream resultStr;
	resultStr << "--Radius = " << GetRadius() << " m" << std::endl
			  << "--Height = " << GetHeight() << " m" << std::endl;
	return resultStr.str();
}
