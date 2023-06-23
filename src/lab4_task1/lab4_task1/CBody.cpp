#include "pch.h"
#pragma hdrstop

#include "CBody.h"
#include "stdafx.h" //подключить в .cpp 
//Прочитать про прекомпилированные заголовки.

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

double CBody::GetDensity() const
{
	return 0.0;
}

double CBody::GetMass() const
{
	return 0.0;
}

double CBody::GetVolume() const
{
	return 0.0;
}

double CBody::GetWeightInWater() const
{
	return 0.0;
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

void CBody::AddBody(std::shared_ptr<CBody> body)
{
}
