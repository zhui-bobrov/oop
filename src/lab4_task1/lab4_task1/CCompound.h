#pragma once
#include "CBody.h"

class CCompound : public CBody
{
public:
	CCompound();

	void AddBody(std::shared_ptr<CBody> body) override;
	double GetVolume() const override;
	double GetMass() const override;
	double GetDensity() const override;
	double GetWeightInWater() const override;

	std::string GetAdditionalParameters() const override;

private:
	std::vector<std::shared_ptr<CBody>> m_subshapesList;
};