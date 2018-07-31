#pragma once
#ifndef ClassPlatform
#include "GameSetUp.h"

class Platform
{
private:
	char platformSign;
	int platformWidth;
	int x, y;
	int score;
public:
	Platform()
	{
		platformSign = char(219);
		platformWidth = 5;
		score = 0;
	}
	void SetCoordinates(int X, int Y, PlatformDirection &dir);
	void BuildingPlatform(int);
	void EnemyPlatformMoveLogic();
	void TouchingTheWall(PlatformDirection &dir);
	void GetKeyboardCommands();
	void MovementDescription(PlatformDirection movement);
	friend class Map;
	friend class Ball;
};

Platform enemyPlatform;
Platform playerPlatform;

#endif // !ClassPlatform
