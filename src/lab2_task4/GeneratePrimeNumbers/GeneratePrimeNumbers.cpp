#include "GeneratePrimeNumbers.h"
#include <iostream>
#include <set>

using namespace std;

const int MAX_UPPER_BOUND = 100000000;

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cerr << "No argument!" << endl;
		return EXIT_FAILURE;
	}
	// std::stoi она позволяет отловить ошибку
	const int upperBound = atoi(argv[1]);
	if (upperBound < 1 || upperBound > MAX_UPPER_BOUND)
	{
		cerr << "Invalid argument!" << endl;
		return EXIT_FAILURE;
	}

	set<int> primeNumbers = SiftNumbers(upperBound);
	PrintNumbers(primeNumbers);
//	cout << primeNumbers.size() << endl;
}