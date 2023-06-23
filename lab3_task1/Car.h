class Car
{
private:
	bool engineOn;
	int currentGear;
	int currentSpeed;

public:
	bool turnOnEngine();
	bool turnOffEngine();
	bool setGear(int newGear);
	bool setSpeed(int newSpeed);
	bool getEngineStatus();
	int getCurrentSpeed();
	int getCurrentGear();
	void info();

private:
	bool isValidSpeed(int gear, int speed);
};