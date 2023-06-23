#pragma once
#include "stdafx.h"
#include "CCompound.h"
#include "CSphere.h"
#include "CCone.h"
#include "CCylinder.h"
#include "CParallelepiped.h"

class BodyConstructor
{
public:
	BodyConstructor();

	std::shared_ptr<CBody> CreateSphere(std::istream& args);
	std::shared_ptr<CBody> CreateCone(std::istream& args);
	std::shared_ptr<CBody> CreateCylinder(std::istream& args);
	std::shared_ptr<CBody> CreateParallelepiped(std::istream& args);
	std::shared_ptr<CBody> CreateCompound();
};