#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

string htmlDecode(string htmlString)
{
	const string interchangeablePairs[5][2] = {
		{"\"", "&quot;"},
		{"'", "&apos;"},
		{"<", "&lt;"},
		{">", "&gt;"},
		{"&", "&amp;"}
	};

	size_t occurrence;
	for (int i = 0; i < (sizeof(interchangeablePairs) / sizeof(interchangeablePairs[0])); i++) {
		do {			
			occurrence = htmlString.find(interchangeablePairs[i][1]);
			if (occurrence != string::npos)
				htmlString.replace(occurrence, interchangeablePairs[i][1].length(), interchangeablePairs[i][0]);
		} while (occurrence != string::npos);
	}

	return htmlString;
}

int main()
{
	string htmlString;
	getline(cin, htmlString);
	
	cout << htmlDecode(htmlString) << endl;
	system("pause");

	return 0;
}