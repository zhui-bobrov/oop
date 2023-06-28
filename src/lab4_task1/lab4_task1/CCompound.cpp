#include "stdafx.h"
#include "CCompound.h"

CCompound::CCompound()
	: CBody("Compound")
	, m_subshapesList()
{
}

void CCompound::AddBody(std::shared_ptr<CBody> body)
{
	m_subshapesList.push_back(body);
}

double CCompound::GetDensity() const
{
	if (m_subshapesList.size() > 0)
	{
		return GetMass() / GetVolume();
	}
	else
	{
		return 0.0;
	}
}

double CCompound::GetVolume() const
{
	double totalVolume = 0.0;
	for (const auto& body : m_subshapesList)
	{
		totalVolume += body->GetVolume();
	}
	return totalVolume;
}

double CCompound::GetMass() const
{
	double totalMass = 0.0;
	for (const auto& body : m_subshapesList)
	{
		totalMass += body->GetMass();
	}
	return totalMass;
}
/*
double CCompound::GetWeightInWater() const
{
	double totalWeightInWater = 0.0;
	for (const auto& body : m_subshapesList)
	{
		totalWeightInWater += body->GetWeightInWater();
	}
	return totalWeightInWater;
}
*/
std::string CCompound::GetAdditionalParameters() const
{
	std::ostringstream resultStr;
	resultStr << "[ "; 
	for (const auto& body : m_subshapesList)
	{
		resultStr << body->GetShapeType() << " ";
	}
	resultStr << "]" << std::endl;
	return resultStr.str();
}
