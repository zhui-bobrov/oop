#pragma once
#include "CBody.h"

class CSolidBody : public CBody
{
public:

	double GetDensity() const override;
	double GetMass() const override;

protected:
	CSolidBody(const std::string& shapeType, double density);

private:
	double m_density;
};
