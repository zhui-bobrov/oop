#include <iostream>
#include <set>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../GeneratePrimeNumbers/GeneratePrimeNumbers.h"

SCENARIO("upperBound 4")
{
	REQUIRE(SiftNumbers(4).size() == 2);
}
//Тестить сами числа
SCENARIO("Is it primes?")
{
	std::set<int> primeNums = SiftNumbers(100000);
	
	auto isPrime = [](int num)
	{
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0) return false;
		}
		return true;
	};
	REQUIRE(std::all_of(primeNums.begin(), primeNums.end(), isPrime));
	
	/*
	std::set<int>::iterator it;
	 for (it = primeNums.begin(); it != primeNums.end(); ++it)
	{
		for (int i = 2; i <= (sqrt(*it)); i++)
		{
			REQUIRE(*it % i != 0);
		}
	}
	*/
}

SCENARIO("upperBound 0")
{
	REQUIRE(SiftNumbers(0).empty());
}

SCENARIO("upperBound 1")
{
	REQUIRE(SiftNumbers(1).empty());
}

SCENARIO("upperBound 2")
{
	REQUIRE(SiftNumbers(2).size() == 1);
}

SCENARIO("upperBound 100")
{
	REQUIRE(SiftNumbers(100).size() == 25);
}

SCENARIO("upperBound 97")
{
	REQUIRE(SiftNumbers(97).size() == 25);
}

SCENARIO("upperBound 100000")
{
	REQUIRE(SiftNumbers(100000).size() == 9592);
}

#ifdef NDEBUG
SCENARIO("upperBound 100000000")
{
	REQUIRE(SiftNumbers(100000000).size() == 5761455);
}

SCENARIO("upperBound 100000001")
{
	REQUIRE(SiftNumbers(100000001).size() == 5761456);
}
#endif
