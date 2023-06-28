#pragma once
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
	ShapeBox(BodyConstructor& bodyConstructor);

	void Init();
	void PrintUsageInfo() const;
	void PrintAllBodies() const;
	void FindHeaviestBody() const;
	void FindLightestBodyInWater() const;

	void CreateBody(std::string args);
	void AddBody(std::shared_ptr<CBody>);

private:
	BodyConstructor m_bodyConstructor;
	std::vector<std::shared_ptr<CBody>> m_shapeList;
	std::map<std::string, std::function<std::shared_ptr<CBody>(std::istream&)>> m_constructorCommandMap;
	std::map<std::string, std::function<void()>> m_commonCommandMap;

	std::shared_ptr<CBody> CreateCompoundBody(std::istream& args);
};