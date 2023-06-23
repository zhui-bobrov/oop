#pragma once
#include "CSolidBody.h"

class CCone : public CSolidBody
{
public:
	CCone(double density, double radius, double height);

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

	std::string GetAdditionalParameters() const override;

private:
	double m_radius;
	double m_height;
};