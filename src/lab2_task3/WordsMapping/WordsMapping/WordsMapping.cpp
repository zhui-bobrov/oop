#include "WordsMapping.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void PrintMap(map<string, int>& wordsMap)
{
	map<string, int>::iterator it;
	for (it = wordsMap.begin(); it != wordsMap.end(); ++it)
		cout << it->first << " -> " << it->second << endl;
}

int main()
{
	map<string, int> wordsMap = ProcessMap();
	PrintMap(wordsMap);

	return EXIT_SUCCESS;
}