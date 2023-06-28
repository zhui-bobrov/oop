#include "stdafx.h"
#include "CSphere.h"

CSphere::CSphere(double density, double radius)
	: CSolidBody("Sphere", density)
	, m_radius(radius)
{
	if (radius <= 0.0)
	{
		throw std::invalid_argument("Invalid radius!");
	}
}

double CSphere::GetRadius() const
{
	return m_radius;
}

double CSphere::GetVolume() const
{
	return (4.0 / 3.0) * PI * std::pow(m_radius, 3);
}

std::string CSphere::GetAdditionalParameters() const
{
	std::ostringstream resultStr;
	resultStr << "--Radius = " << GetRadius() << " m" << std::endl;
	return resultStr.str();
}
