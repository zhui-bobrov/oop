#include "pch.h"
#pragma hdrstop

#include "CParallelepiped.h"

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	: CSolidBody("Parallelepiped", density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
	if (width <= 0.0)
	{
		throw std::invalid_argument("Invalid width!");
	}

	if (height <= 0.0)
	{
		throw std::invalid_argument("Invalid height!");
	}

	if (depth <= 0.0)
	{
		throw std::invalid_argument("Invalid depth!");
	}
}

double CParallelepiped::GetWidth() const
{
	return m_width;
}

double CParallelepiped::GetHeight() const
{
	return m_height;
}

double CParallelepiped::GetDepth() const
{
	return m_depth;
}

double CParallelepiped::GetVolume() const
{
	return m_width * m_height * m_depth;
}

std::string CParallelepiped::GetAdditionalParameters() const
{
	std::ostringstream resultStr;
	resultStr << "--Width = " << GetWidth() << " m" << std::endl
			  << "--Height = " << GetHeight() << " m" << std::endl
			  << "--Depth = " << GetDepth() << " m" << std::endl;
	return resultStr.str();
}
