#include "stdafx.h" //подключить в .cpp (+)
#include "CBody.h"
//Прочитать про прекомпилированные заголовки (прочитал, но не особо понял).

CBody::CBody(const std::string& shapeType)
	: m_shapeType(shapeType)
{
	if (shapeType.empty())
	{
		throw std::invalid_argument("shapeType is empty!");
	}
}

CBody::~CBody()
{
}

std::string CBody::GetShapeType() const
{
	return m_shapeType;
}

void CBody::AddBody(std::shared_ptr<CBody> body)
{
}

double CBody::GetWeightInWater() const
{
	return (GetDensity() - WATER_DENSITY) * G * GetVolume();
}

std::string CBody::ToString() const
{
	std::ostringstream resultStr;
	resultStr << GetShapeType() << ":" << std::endl
			  << std::fixed << std::setprecision(3)
			  << "--Density = " << GetDensity() << " kg/m³" << std::endl
			  << "--Volume = " << GetVolume() << " m³" << std::endl
			  << "--Mass = " << GetMass() << " kg" << std::endl
			  << "--In water = " << GetWeightInWater() << std::endl
			  << GetAdditionalParameters();
	return resultStr.str();
}

std::string CBody::GetAdditionalParameters() const
{
	return "";
}
