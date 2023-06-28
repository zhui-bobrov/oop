#pragma once
#include "CSolidBody.h"

class CCylinder : public CSolidBody
{
public:
	CCylinder(double density, double radius, double height);

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const override;


private:
	double m_radius;
	double m_height;
	std::string GetAdditionalParameters() const override;
};