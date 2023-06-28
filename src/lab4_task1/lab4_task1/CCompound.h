#pragma once
#include "CBody.h"

class CCompound : public CBody
{
public:
	CCompound();

	double GetVolume() const override;
	double GetMass() const override;
	double GetDensity() const override;

	void AddBody(std::shared_ptr<CBody> body) override;

private:
	std::vector<std::shared_ptr<CBody>> m_subshapesList;
	std::string GetAdditionalParameters() const override;
};