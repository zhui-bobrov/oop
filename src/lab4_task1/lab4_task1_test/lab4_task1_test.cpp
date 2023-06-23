#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../lab4_task1/ShapeBox.h"

TEST_CASE("CSphere Test")
{
	CSphere sphere(2000, 0.5);
	CHECK(sphere.GetShapeType() == "Sphere");
	CHECK(sphere.GetDensity() == 2000.0);
	CHECK(sphere.GetRadius() == 0.5);
	CHECK(sphere.GetVolume() == Approx(0.5).margin(0.1));
	CHECK(sphere.GetMass() == Approx(1047.1).margin(0.1));
	CHECK(sphere.GetWeightInWater() == Approx(5235.9).margin(0.1));
}

TEST_CASE("CCone Test")
{
	CCone cone(1500, 2, 4);
	CHECK(cone.GetShapeType() == "Cone");
	CHECK(cone.GetDensity() == 1500);
	CHECK(cone.GetRadius() == 2);
	CHECK(cone.GetHeight() == 4);
	CHECK(cone.GetVolume() == Approx(16.7).margin(0.1));
	CHECK(cone.GetMass() == Approx(25132.7).margin(0.1));
	CHECK(cone.GetWeightInWater() == Approx(83775.8).margin(0.1));
}

TEST_CASE("CCylinder Test")
{
	CCylinder cylinder(900, 2, 10);
	CHECK(cylinder.GetShapeType() == "Cylinder");
	CHECK(cylinder.GetDensity() == 900);
	CHECK(cylinder.GetRadius() == 2);
	CHECK(cylinder.GetHeight() == 10);
	CHECK(cylinder.GetVolume() == Approx(125.664).margin(0.1));
	CHECK(cylinder.GetMass() == Approx(113097.336).margin(0.1));
	CHECK(cylinder.GetWeightInWater() == Approx(-125663.7).margin(0.1));
}

TEST_CASE("CParallelepiped Test")
{
	CParallelepiped parallelepiped(5000, 0.2, 0.1, 0.3);
	CHECK(parallelepiped.GetShapeType() == "Parallelepiped");
	CHECK(parallelepiped.GetDensity() == 5000);
	CHECK(parallelepiped.GetWidth() == 0.2);
	CHECK(parallelepiped.GetHeight() == 0.1);
	CHECK(parallelepiped.GetDepth() == 0.3);
	CHECK(parallelepiped.GetVolume() == Approx(0.006).margin(0.1));
	CHECK(parallelepiped.GetMass() == Approx(30).margin(0.1));
	CHECK(parallelepiped.GetWeightInWater() == Approx(240).margin(0.1));
}

TEST_CASE("CCompound Test")
{
	std::shared_ptr<CBody> sphere = std::make_shared<CSphere>(2000, 0.5);
	std::shared_ptr<CBody> cone = std::make_shared<CCone>(1500, 2, 4);
	std::shared_ptr<CBody> cylinder = std::make_shared<CCylinder>(900, 2, 10);
	std::shared_ptr<CBody> parallelepiped = std::make_shared<CParallelepiped>(5000, 0.2, 0.1, 0.3);

	CCompound compound;
	compound.AddBody(sphere);
	compound.AddBody(cone);
	compound.AddBody(cylinder);
	compound.AddBody(parallelepiped);

	CHECK(compound.GetShapeType() == "Compound");
	CHECK(compound.GetDensity() == Approx(974.5).margin(0.1));
	CHECK(compound.GetVolume() == (sphere->GetVolume() + cone->GetVolume() + cylinder->GetVolume() + parallelepiped->GetVolume()));
	CHECK(compound.GetMass() == (sphere->GetMass() + cone->GetMass() + cylinder->GetMass() + parallelepiped->GetMass())); 
	CHECK(compound.GetWeightInWater() == (sphere->GetWeightInWater() + cone->GetWeightInWater() + cylinder->GetWeightInWater() + parallelepiped->GetWeightInWater()));
}

TEST_CASE("Empty CCompound Test")
{

	CCompound compound;

	CHECK(compound.GetShapeType() == "Compound");
	CHECK(compound.GetDensity() == 0);
	CHECK(compound.GetVolume() == 0);
	CHECK(compound.GetMass() == 0); 
	CHECK(compound.GetWeightInWater() == 0);
}

TEST_CASE("Invalid args")
{
	BodyConstructor bodyConstructor;
	ShapeBox shapeBox(bodyConstructor);
	WHEN("Sphere invalid density == 0")
	{
		THEN("Invalid density message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere 0"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere -1"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere "), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere nope"), "Invalid density!");
		}
	}
	WHEN("Sphere invalid radius")
	{
		THEN("Invalid radius message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere 10"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere 10 0"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere 10 -1"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere 10 "), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Sphere 10 nope"), "Invalid radius!");
		}
	}

	WHEN("Cone invalid density")
	{
		THEN("Invalid density message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 0"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone -1"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone "), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone nope"), "Invalid density!");
		}
	}
	WHEN("Cone invalid radius")
	{
		THEN("Invalid radius message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 0"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 -1"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 "), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 nope"), "Invalid radius!");
		}
	}
	WHEN("Cone invalid height")
	{
		THEN("Invalid radius height")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 10"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 10 0"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 10 -1"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 10 "), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cone 10 10 nope"), "Invalid height!");
		}
	}

	WHEN("Cylinder invalid density")
	{
		THEN("Invalid density message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 0"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder -1"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder "), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder nope"), "Invalid density!");
		}
	}
	WHEN("Cylinder invalid radius")
	{
		THEN("Invalid radius message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 0"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 -1"), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 "), "Invalid radius!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 nope"), "Invalid radius!");
		}
	}
	WHEN("Cylinder invalid height")
	{
		THEN("Invalid radius height")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 10"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 10 0"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 10 -1"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 10 "), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Cylinder 10 10 nope"), "Invalid height!");
		}
	}

	WHEN("Parallelepiped invalid density")
	{
		THEN("Invalid density message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 0"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped -1"), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped "), "Invalid density!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped nope"), "Invalid density!");
		}
	}
	WHEN("Parallelepiped invalid width")
	{
		THEN("Invalid radius message")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10"), "Invalid width!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 0"), "Invalid width!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 -1"), "Invalid width!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 "), "Invalid width!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 nope"), "Invalid width!");
		}
	}
	WHEN("Parallelepiped invalid height")
	{
		THEN("Invalid radius height")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 0"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 -1"), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 "), "Invalid height!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 nope"), "Invalid height!");
		}
	}
	WHEN("Parallelepiped invalid depth")
	{
		THEN("Invalid radius depth")
		{
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 10"), "Invalid depth!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 10 0"), "Invalid depth!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 10 -1"), "Invalid depth!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 10"), "Invalid depth!");
			CHECK_THROWS_WITH(shapeBox.CreateBody("Parallelepiped 10 10 10 nope"), "Invalid depth!");
		}
	}
	
	
}