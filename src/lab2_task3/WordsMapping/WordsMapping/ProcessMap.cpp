#include "WordsMapping.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> ProcessMap()
{
	string input;
	map<string, int> wordsMap;
	map<string, int>::iterator it;
	while (cin >> input)
	{
		transform(input.begin(), input.end(), input.begin(), ::tolower);
		it = wordsMap.find(input);
		if (it != wordsMap.end())
		{
			wordsMap[input] += 1;
		}
		else
		{
			wordsMap.insert(make_pair(input, 1));
		}
	}
	return wordsMap;
}