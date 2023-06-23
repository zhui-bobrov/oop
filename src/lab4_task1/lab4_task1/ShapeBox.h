#pragma once
#include "stdafx.h"
#include "CBody.h"
#include "CCompound.h"
#include "CSphere.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"
#include "BodyConstructor.h"

class ShapeBox
{
public:
	//Убратьв приват ненужное.
	ShapeBox(BodyConstructor& bodyConstructor);
	BodyConstructor m_bodyConstructor;
	std::map<std::string, std::function<std::shared_ptr<CBody>(std::istream&)>> m_commandMap;

	void Init();
	void PrintUsageInfo() const;
	void CreateBody(std::string args);
	std::shared_ptr<CBody> CreateCompoundBody(std::istream& args);
	void AddBody(std::shared_ptr<CBody>);
	void PrintAllBodies() const;
	void FindHeaviestBody() const;
	void FindLightestBodyInWater() const;

private:
	std::map<std::string, std::function<std::shared_ptr<CBody>(std::istream&)>> m_constructorCommandMap;
	std::map<std::string, std::function<void()>> m_commonCommandMap;
	std::vector<std::shared_ptr<CBody>> m_shapeList;
};