#include <iostream>
#include "MapFunctions.h"
#include "GameMovement.h"
#include "GameRules.h"

using namespace std;

int main()
{
	Map map;
	while (gameOver == false)
	{
		BallMovementDescription();
		EnemyMovementDescription();
		enemyPlatform.EnemyPlatformMoving();
		GetKeyboardCommands();
		ball.BallReset();
		ball.BallTouchingPlayerPlatform();
		ball.BallTouchingEnemyPlatform();
		ball.BallTouchingTheWall();
		playerPlatform.PlatformTouchingTheWall();
		map.BuildingMap();
		ClearScreen();
		Sleep(100);
	}
	return 0;
}