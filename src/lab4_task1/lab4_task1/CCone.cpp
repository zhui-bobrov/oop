#include "stdafx.h"
#include "CCone.h"

CCone::CCone(double density, double radius, double height)
	: CSolidBody("Cone", density)
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

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return (1.0 / 3.0) * PI * std::pow(m_radius, 2) * m_height;
}

std::string CCone::GetAdditionalParameters() const
{
	std::ostringstream resultStr;
	resultStr << "--Radius = " << GetRadius() << " m" << std::endl
			  << "--Height = " << GetHeight() << " m" << std::endl;
	return resultStr.str();
}
