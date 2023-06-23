#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;
map<string, int> ProcessMap() {
	string input;
	map<string, int> wordsMap;
	map<string, int>::iterator it;
	while (cin >> input)
	{
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		it = wordsMap.find(input);
		if (it != wordsMap.end()) {
			wordsMap[input] += 1;
		}
		else {
			wordsMap.insert(make_pair(input, 1));
		}
	}
	return wordsMap;
}

void PrintMap(map<string, int>& wordsMap) {
	map<string, int>::iterator it;
	for (it = wordsMap.begin(); it != wordsMap.end(); ++it)
		cout << it -> first << " -> " << it -> second << endl;
}

int main() {
	PrintMap(ProcessMap());

	system("pause");
	return EXIT_SUCCESS;
}