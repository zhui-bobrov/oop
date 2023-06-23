#pragma once
#include "CSolidBody.h"

class CSphere : public CSolidBody
{
public:
	CSphere(double density, double radius);

	double GetVolume() const override;
	double GetRadius() const;

	virtual std::string GetAdditionalParameters() const;

private:
	double m_radius;
};