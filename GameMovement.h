#pragma once
#ifndef GameMovement
#include <conio.h>
#include "MapFunctions.h"

enum class BallMovement
{
	down, up, downRigth, upLeft, downLeft, upRigth
};

enum class PlatformMovement
{
	stop, left, right
};

BallMovement ballMove;
PlatformMovement enemyPlatformMove;

void GetKeyboardCommands() //player move
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			playerPlatformX--;
			break;
		case 'd':
			playerPlatformX++;
			break;
		}
	}
}

void EnemyMovementDescription()
{
	switch (enemyPlatformMove)
	{
	case PlatformMovement::left:
		enemyPlatformX--;
		break;
	case PlatformMovement::right:
		enemyPlatformX++;
		break;
	}
}

void BallMovementDescription()
{
	switch (ballMove)
	{
	case BallMovement::down:
		ballY++;
		break;
	case BallMovement::up:
		ballY--;
		break;
	case BallMovement::upLeft:
		ballX--;
		ballY--;
		break;
	case BallMovement::upRigth:
		ballX++;
		ballY--;
		break;
	case BallMovement::downLeft:
		ballX--;
		ballY++;
		break;
	case BallMovement::downRigth:
		ballX++;
		ballY++;
		break;
	}
}

#endif // !GameMovement
