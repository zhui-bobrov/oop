#include "GeneratePrimeNumbers.h"
#include <iostream>

using namespace std;

void PrintNumbers(set<int> numbersVector)
{
	for (int number : numbersVector)
		cout << number << ' ';
}