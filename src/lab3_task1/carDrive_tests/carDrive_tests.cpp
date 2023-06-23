#include <iostream>
#include <set>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"
#include "../lab3_task1/Car.h"

SCENARIO("Car init")
{
	Car car;
	CHECK(car.GetEngineStatus() == false);
	CHECK(car.GetCurrentGear() == 0);
	CHECK(car.GetCurrentSpeed() == 0);
	CHECK(car.GetDirection() == Direction::Stand);
}

SCENARIO("Turn on engine")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
}

SCENARIO("Turn off engine")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.TurnOffEngine() == true);
}

SCENARIO("Get engine status")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	CHECK(car.GetEngineStatus() == true);
	REQUIRE(car.TurnOffEngine());
	CHECK(car.GetEngineStatus() == false);
}

SCENARIO("Engine off gear changing")
{
	Car car;
	CHECK(car.SetGear(-1) == false);
	CHECK(car.SetGear(0) == false);
	CHECK(car.SetGear(1) == false);
	CHECK(car.SetGear(2) == false);
	CHECK(car.SetGear(3) == false);
	CHECK(car.SetGear(4) == false);
	CHECK(car.SetGear(5) == false);
}

SCENARIO("Engine off speed changing")
{
	Car car;
	CHECK(car.SetSpeed(1) == false);
	CHECK(car.SetSpeed(10) == false);
}

SCENARIO("Zero gear speed changing")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	CHECK(car.SetSpeed(1) == false);
	CHECK(car.SetSpeed(10) == false);
}

SCENARIO("Zero speed gear changing")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	CHECK(car.SetGear(-1) == true);
	CHECK(car.SetGear(0) == true);
	CHECK(car.SetGear(1) == true);
	CHECK(car.SetGear(2) == false);
	CHECK(car.SetGear(3) == false);
	CHECK(car.SetGear(4) == false);
	CHECK(car.SetGear(5) == false);
}

SCENARIO("-1/1 gear changing")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(-1) == true);
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetGear(-1) == true);
}

SCENARIO("Gear-Speed limits")
{
	Car car;
	car.TurnOnEngine();
	REQUIRE(car.SetGear(-1));
	CHECK(car.SetSpeed(20) == true);
	CHECK(car.SetSpeed(21) == false);
	CHECK(car.SetSpeed(0) == true);
	REQUIRE(car.SetGear(0));
	CHECK(car.SetSpeed(30) == false);
	REQUIRE(car.SetGear(1));
	CHECK(car.SetSpeed(0) == true);
	CHECK(car.SetSpeed(30) == true);
	CHECK(car.SetSpeed(31) == false);
	REQUIRE(car.SetGear(2));
	CHECK(car.SetSpeed(19) == false);
	CHECK(car.SetSpeed(20) == true);
	CHECK(car.SetSpeed(50) == true);
	CHECK(car.SetSpeed(51) == false);
	REQUIRE(car.SetGear(3));
	CHECK(car.SetSpeed(29) == false);
	CHECK(car.SetSpeed(30) == true);
	CHECK(car.SetSpeed(60) == true);
	CHECK(car.SetSpeed(61) == false);
	REQUIRE(car.SetGear(4));
	CHECK(car.SetSpeed(39) == false);
	CHECK(car.SetSpeed(40) == true);
	CHECK(car.SetSpeed(90) == true);
	CHECK(car.SetSpeed(91) == false);
	REQUIRE(car.SetGear(5));
	CHECK(car.SetSpeed(49) == false);
	CHECK(car.SetSpeed(50) == true);
	CHECK(car.SetSpeed(150) == true);
	CHECK(car.SetSpeed(151) == false);
	REQUIRE(car.SetGear(0));
	CHECK(car.SetSpeed(151) == false);
	CHECK(car.SetSpeed(50) == true);
	CHECK(car.SetSpeed(0) == true);
}

SCENARIO("Bad Gears")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	CHECK(car.SetGear(-2) == false);
	CHECK(car.SetGear(6) == false);
}

SCENARIO("Negative speed")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(1));
	REQUIRE(car.SetSpeed(-10) == false);
}

SCENARIO("Turn off engine on the speed")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	REQUIRE(car.SetGear(1));
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.TurnOffEngine() == false);
}

SCENARIO("Direction test")
{
	Car car;
	REQUIRE(car.TurnOnEngine());
	CHECK(car.GetDirection() == Direction::Stand);
	REQUIRE(car.SetGear(-1));
	CHECK(car.GetDirection() == Direction::Stand);
	REQUIRE(car.SetSpeed(10) == true);
	CHECK(car.GetDirection() == Direction::Back);
	REQUIRE(car.SetSpeed(0) == true);
	CHECK(car.GetDirection() == Direction::Stand);
	REQUIRE(car.SetGear(0));
	CHECK(car.GetDirection() == Direction::Stand);
	REQUIRE(car.SetGear(1));
	CHECK(car.GetDirection() == Direction::Stand);
	REQUIRE(car.SetSpeed(10) == true);
	CHECK(car.GetDirection() == Direction::Forward);
	REQUIRE(car.SetSpeed(0) == true);
	CHECK(car.GetDirection() == Direction::Stand);
	REQUIRE(car.SetGear(0));
	CHECK(car.GetDirection() == Direction::Stand);
}
