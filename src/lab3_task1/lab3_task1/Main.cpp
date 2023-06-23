#include "stdfx.h"
#include "Car.h"
#include "Driver.h"


using namespace std;
int main()
{
	Car car;
	Driver driver(car);

	string line;
	map<string, function<void(istream&)>> commandMap = {
		{ "Info",		[&](istream& args) { driver.Info(); } },
		{ "EngineOn",	[&](istream& args) { driver.EngineOn(); } },
		{ "EngineOff",	[&](istream& args) { driver.EngineOff(); } },
		{ "SetGear",	[&](istream& args) { driver.SetGear(args); } },
		{ "SetSpeed",	[&](istream& args) { driver.SetSpeed(args); } }
	};

	while (true)
	{
		getline(cin, line);

		istringstream commandLine(line);
		string command;
		commandLine >> command;

		if (commandMap.find(command) != commandMap.end())
		{
			commandMap[command](commandLine);
		}
		else
		{
			cout << line << " - Unknown command!" << endl;
		}
		cout << "----------------" << endl;
	}

	return 0;
}
