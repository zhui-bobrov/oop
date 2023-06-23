#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<double> ReceiveVector()
{
	//TODO: ограничить зону видимости
	vector<double> numVector;
	cout << "Enter doubles: " << endl;
	
	while (!cin.eof()) {
		double number;
		if (cin >> number) {
			numVector.push_back(number);
		}
		else {
			break;
		}
	}
	return numVector;
}

void PrintVector(vector<double>& numVector) { //TODO: именовать с заглавной и переименовать на print
	cout << "Processed Vector: " << endl;
	sort(numVector.begin(), numVector.end());
	for (int i = 0; i < numVector.size(); i++)
		cout << numVector[i] << " ";
		cout << numVector[i] << " ";
	cout << endl;
}

double CalculateMultiplier(vector<double>& numVector) {
	const int multiplier = 2;
	double evenSum = 0;
	int evenCount = 0;
	for (int i = 0; i < numVector.size(); i++) {
		if (fmod(numVector[i], multiplier) == 0) //TODO: вынести в константу
		{
			evenSum += numVector[i];
			evenCount++;
		}
	}

	return evenSum / evenCount;
}

vector<double> ProcessVector(vector<double>& numVector) {
	double multiplier = CalculateMultiplier(numVector);

	for (int i = 0; i < numVector.size(); i++) {
		if (fmod(numVector[i], 3) == 0) {
			numVector[i] = numVector[i] * multiplier;
		}
	}
	return numVector;
}


int main() {
	vector<double> numVector;

	numVector = ReceiveVector();
	numVector = ProcessVector(numVector);
	PrintVector(numVector);

	system("pause");
	return 0;
}