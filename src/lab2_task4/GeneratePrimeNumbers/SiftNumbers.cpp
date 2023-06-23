#include "GeneratePrimeNumbers.h"
#include <set>
#include <vector>

using namespace std;

set<int> SiftNumbers(int upperBound)
{
	set<int> primeNumbers;
	vector<bool> numbersVector(upperBound + 1, true);
	double upperLimit = sqrt(upperBound);
	for (int i = 2; i < numbersVector.size(); i++)
	{
		if (numbersVector[i])
		{
			primeNumbers.insert(primeNumbers.end(), i); //инсерт принимающий итератор хинт
			if (i <= upperLimit) //Нет теста для ситуации
			{
				//сделать переменную степ, если стен >2 стеналь степ 2х (т.к. все чётные вылетели)
				int step = i > 2 ? i * 2 : i;
				for (int j = i * i; j <= upperBound; j += step)
				{
					numbersVector[j] = false;
				}
			}
		}
	}
	return primeNumbers;
}