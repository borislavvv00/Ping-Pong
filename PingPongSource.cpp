#include "MapFunctions.h"
#include "GameMovement.h"
#include "GameRules.h"

int main()
{
	Map map;
	playerPlatform.SetCoordinates(WIDTH / 2 - 2, HIGH - 3, playerDirection);
	enemyPlatform.SetCoordinates(WIDTH / 2 - 2, 3, enemyDirection);
	ball.SetCoordinates();

	while (isGameOver == false)
	{
		playerPlatform.MovementDescription(playerDirection);
		playerPlatform.GetKeyboardCommands();
		playerPlatform.TouchingTheWall(playerDirection);

		enemyPlatform.MovementDescription(enemyDirection);
		enemyPlatform.EnemyPlatformMoveLogic();
		enemyPlatform.TouchingTheWall(enemyDirection);

		ball.MovementDescription();
		ball.TouchingPlayerPlatform();
		ball.TouchingEnemyPlatform();
		ball.TouchingTheWall();

		map.BuildingMap();
		map.Reset();

		ClearScreen();
		Sleep(100);
	}
	return 0;
}
