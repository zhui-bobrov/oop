#include <iostream>
#include <string>

#include "Car.h"

using namespace std;

int main()
{
	Car car;
	string command;

	while (true)
    {
		getline(cin, command);

        if (command == "Info")
        {
            car.info();
        }
        
        if (command == "EngineOn")
        {
			if (car.turnOnEngine())
			{
				cout << "��������� �������." << endl;
			}
			else
			{
				cout << "��������� �� �������." << endl;
			}
        }
        
        if (command == "EngineOff")
        {
            if (car.turnOffEngine())
            {
                cout << "��������� ��������." << endl;
            }
            else
            {
                cout << "��������� �� �����." << endl;
            }
        }
        
        if (command.substr(0, command.find(' ')) == "SetGear")
        {
			int gear = stoi(command.substr(command.find_last_of(' ') + 1));
            if (car.setGear(gear))
            {
                cout << "�������� ��������." << endl;
            }
            else
            {
                cout << "���-�� ���������." << endl;
            }
        }
		
        if (command.substr(0, command.find(' ')) == "SetSpeed")
        {
			int speed = stoi(command.substr(command.find_last_of(' ') + 1));
            if (car.setSpeed(speed))
            {
                cout << "�������� ��������." << endl;
            }
            else
            {
                cout << "�������� �� ��������." << endl;
            }
        }

        cout << endl;
    }

    return 0;
}