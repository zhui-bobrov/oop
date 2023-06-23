#pragma once
#include "CBody.h"

class CSolidBody : public CBody
{
public:
	CSolidBody(const std::string& shapeType, double density);

	double GetDensity() const override;
	double GetMass() const override;
	double GetWeightInWater() const override;

private:
	double m_density;
};