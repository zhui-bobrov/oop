#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string HtmlDecode(string htmlString)
{
	const string specialPairs[][2] = {
		{ "\"", "&quot;" },
		{ "'", "&apos;" },
		{ "<", "&lt;" },
		{ ">", "&gt;" },
		{ "&", "&amp;" }
	};

	int specialPairsCount = sizeof(specialPairs) / sizeof(specialPairs[0]);
	for (int i = 0; i < specialPairsCount; i++)
	{
		size_t occurrence;
		do
		{
			occurrence = htmlString.find(specialPairs[i][1]);
			if (occurrence != string::npos)
				htmlString.replace(occurrence, specialPairs[i][1].length(), specialPairs[i][0]);
		} while (occurrence != string::npos);
	}

	return htmlString;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		cerr << "Error, no text here!" << endl;
		return EXIT_FAILURE;
	}
	string htmlString = argv[1];
	cout << HtmlDecode(htmlString) << endl;

	return EXIT_SUCCESS;
}