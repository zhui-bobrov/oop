#include "pch.h"
#pragma hdrstop

#include "ShapeBox.h"

ShapeBox::ShapeBox(BodyConstructor& bodyConstructor)
	: m_bodyConstructor(bodyConstructor)
{
	m_constructorCommandMap = {
		{ "Sphere", [&](std::istream& args) { return m_bodyConstructor.CreateSphere(args); } },
		{ "Cone", [&](std::istream& args) { return m_bodyConstructor.CreateCone(args); } },
		{ "Cylinder", [&](std::istream& args) { return m_bodyConstructor.CreateCylinder(args); } },
		{ "Parallelepiped", [&](std::istream& args) { return m_bodyConstructor.CreateParallelepiped(args); } },
		{ "Compound", [&](std::istream& args) { return CreateCompoundBody(args); } }
	};

	m_commonCommandMap = {
		{ "Info",		[&]() { PrintAllBodies(); } },
		{ "Heaviest",	[&]() { FindHeaviestBody(); } },
		{ "Lightest",	[&]() { FindLightestBodyInWater(); } },
		{ "Help",		[&]() { PrintUsageInfo(); } }
	};

}

void ShapeBox::Init()
{	
	PrintUsageInfo();
	std::vector<std::shared_ptr<CBody>> bodies;
	std::string commandLine;

	while (std::getline(std::cin, commandLine))
	{
		std::shared_ptr<CBody> body;
		std::istringstream arguments(commandLine);
		std::string command;
		arguments >> command;

		if (m_constructorCommandMap.find(command) != m_constructorCommandMap.end())
		{
			try
			{
				body = m_constructorCommandMap[command](arguments);
			}
			catch (const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}

			if (body != nullptr)
			{
				AddBody(body);
				std::cout << command << " added to the list." << std::endl;
			}
		}
		else if (m_commonCommandMap.find(command) != m_commonCommandMap.end())
		{
			m_commonCommandMap[command]();
		}
		else
		{
			std::cout << "Unknown command!" << std::endl;
		}
		std::cout << "----------------" << std::endl;
	}
}

void ShapeBox::AddBody(std::shared_ptr<CBody> body)
{
	m_shapeList.push_back(body);
}

void ShapeBox::CreateBody(std::string args)
{

	std::istringstream arguments(args);
	std::string command;
	arguments >> command;	

	std::shared_ptr<CBody> body;
	body = m_constructorCommandMap[command](arguments);
	AddBody(body);
}

std::shared_ptr<CBody> ShapeBox::CreateCompoundBody(std::istream& args)
{
	std::string commandLine;
	std::shared_ptr<CBody> body;
	body = m_bodyConstructor.CreateCompound();
	while (std::getline(std::cin, commandLine))
	{
		std::istringstream arguments(commandLine);
		std::string command;
		arguments >> command;

		if (command == "End")
		{
			break;
		}

		if (m_constructorCommandMap.find(command) != m_constructorCommandMap.end())
		{
			std::shared_ptr<CBody> subbody;
			subbody = m_constructorCommandMap[command](arguments);
			body->AddBody(subbody);
		}
		else
		{
			std::cout << "Unknown command!" << std::endl;
		}		
	}
	return body;
}

void ShapeBox::PrintAllBodies() const
{
	if (m_shapeList.size() > 0)
	{
		std::cout << "All bodies:" << std::endl;
		for (auto& body : m_shapeList)
		{
			std::cout << body->ToString() << std::endl;
		}
	}
	else
	{
		std::cout << "No bodies around." << std::endl;
	}
}

void ShapeBox::FindHeaviestBody() const
{
	std::shared_ptr<CBody> heaviestBody;
	double maxMass = 0.0;

	for (const auto& body : m_shapeList)
	{
		double mass = body->GetMass();
		if (mass > maxMass)
		{
			maxMass = mass;
			heaviestBody = body;
		}
	}

	if (heaviestBody != nullptr)
	{
		std::cout << "Heaviest body: " << std::endl;
		std::cout << heaviestBody->ToString() << std::endl;
	}
	else
	{
		std::cout << "No bodies around." << std::endl;
	}
}

void ShapeBox::FindLightestBodyInWater() const
{
	std::shared_ptr<CBody> lightestBody;
	double minWeightInWater = std::numeric_limits<double>::max();

	for (const auto& body : m_shapeList)
	{
		double weightInWater = body->GetWeightInWater();
		if (weightInWater < minWeightInWater)
		{
			minWeightInWater = weightInWater;
			lightestBody = body;
		}
	}

	if (lightestBody != nullptr)
	{
		std::cout << "Lightest body in water: " << std::endl;
		std::cout << lightestBody->ToString() << std::endl;
	}
	else
	{
		std::cout << "No bodies around." << std::endl;
	}
}

void ShapeBox::PrintUsageInfo() const
{
	std::cout << "Usage info:" << std::endl
			  << "  Program uses the following units of measurement: m, m3, kg, kg/m3 " << std::endl
			  << "  Available shapes:" << std::endl
			  << "  -- Cone [density] [radius] [height]" << std::endl
			  << "  -- Sphere [density] [radius]" << std::endl
			  << "  -- Cylinder [density] [radius] [height]" << std::endl
			  << "  -- Parallelepiped [density] [width] [height] [depth]" << std::endl
			  << "  -- Compound - to create composite body" << std::endl
			  << "  -- End - to stop creating composite body" << std::endl
			  << "  Info - to print all bodies" << std::endl
			  << "  Heaviest - to print heaviest body" << std::endl
			  << "  Lightest - to print lightest body in water" << std::endl
			  << "  Help - to print usage info" << std::endl;
}
