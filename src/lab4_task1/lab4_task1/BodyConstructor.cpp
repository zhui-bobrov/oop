#include "stdafx.h"
#include "BodyConstructor.h"

BodyConstructor::BodyConstructor()
{
}

std::shared_ptr<CBody> BodyConstructor::CreateSphere(std::istream& args)
{
	double density, radius;

	args >> density >> radius;
	return std::make_shared<CSphere>(density, radius);
}

std::shared_ptr<CBody> BodyConstructor::CreateCone(std::istream& args)
{
	double density, radius, height;

	args >> density >> radius >> height;
	return std::make_shared<CCone>(density, radius, height);
}

std::shared_ptr<CBody> BodyConstructor::CreateCylinder(std::istream& args)
{
	double density, radius, height;

	args >> density >> radius >> height;
	return std::make_shared<CCylinder>(density, radius, height);
}

std::shared_ptr<CBody> BodyConstructor::CreateParallelepiped(std::istream& args)
{
	double density, width, height, depth;

	args >> density >> width >> height >> depth;
	return std::make_shared<CParallelepiped>(density, width, height, depth);
}

std::shared_ptr<CBody> BodyConstructor::CreateCompound()
{
	return std::make_shared<CCompound>();
}

