#pragma once
#include "CSolidBody.h"

class CCone : public CSolidBody
{
public:
	CCone(double density, double radius, double height);

	double GetVolume() const override;
	double GetRadius() const;
	double GetHeight() const;


private:
	double m_radius;
	double m_height;
	std::string GetAdditionalParameters() const override;
};

