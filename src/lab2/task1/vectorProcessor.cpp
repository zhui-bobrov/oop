#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<double> receiveVector()
{
	double input;
	vector<double> numVector;

	cout << "Enter doubles: " << endl;
/*	do {
		std::cin >> input;
		numVector.push_back(input);
	} while (input);
*/
	
	while (cin >> input)
	{
		numVector.push_back(input);
	};

	return numVector;
}

void returnVector(vector<double>& numVector)
{
	cout << "Processed Vector: " << endl;
	sort(numVector.begin(), numVector.end());
	for (int i = 0; i < numVector.size(); i++)
		cout << numVector[i] << " ";
	cout << endl;
}

double calculateMultiplier(vector<double>& numVector)
{
	double evenSum = 0;
	int evenCount = 0;
	for (int i = 0; i < numVector.size(); i++)
		if (fmod(numVector[i], 2) == 0)
		{
			evenSum += numVector[i];
			evenCount++;
		}

	return evenSum / evenCount;
}

vector<double>  processVector(vector<double>& numVector)
{
	double multiplier = calculateMultiplier(numVector);

	for (int i = 0; i < numVector.size(); i++)
		if (fmod(numVector[i], 3) == 0)
		{
			numVector[i] = numVector[i] * multiplier;
		}

	return numVector;
}


int main()
{
	vector<double> numVector;
	double num;

	numVector = receiveVector();
	numVector = processVector(numVector);
	returnVector(numVector);

	system("pause");
	return 0;
}