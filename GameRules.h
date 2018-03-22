#pragma once
#ifndef GameRules
#include "MapFunctions.h"
#include "GameMovement.h"

void Ball::BallTouchingPlayerPlatform()
{
	if (ballX == playerPlatformX + 2 && ballY == playerPlatformY - 1)
	{
		ballMove = BallMovement::up;
		ballTrajectory = 1;
	}
	else if ((ballX == playerPlatformX || ballX == playerPlatformX + 1) && ballY == playerPlatformY - 1)
	{
		ballMove = BallMovement::upLeft;
		ballTrajectory = 1;
	}
	else if ((ballX == playerPlatformX + 3 || ballX == playerPlatformX + 4) && ballY == playerPlatformY - 1)
	{
		ballMove = BallMovement::upRigth;
		ballTrajectory = 1;
	}
}

void Ball::BallTouchingEnemyPlatform()
{
	if (ballX == enemyPlatformX + 2 && ballY == enemyPlatformY + 1)
	{
		ballMove = BallMovement::down;
		ballTrajectory = 0;
	}
	else if ((ballX == enemyPlatformX || ballX == enemyPlatformX + 1) && ballY == enemyPlatformY + 1)
	{
		ballMove = BallMovement::downLeft;
		ballTrajectory = 0;
	}
	else if ((ballX == enemyPlatformX + 3 || ballX == enemyPlatformX + 4) && ballY == enemyPlatformY + 1)
	{
		ballMove = BallMovement::downRigth;
		ballTrajectory = 0;
	}
}

void Ball::BallTouchingTheWall()
{
	switch (ballTrajectory)
	{
	case 0:
		if (ballX == 0)
		{
			ballMove = BallMovement::upRigth;
		}
		else if (ballX == WIDTH)
		{
			ballMove = BallMovement::upLeft;
		}
		break;
	case 1:
		if (ballX == 0)
		{
			ballMove = BallMovement::downRigth;
		}
		else if (ballX == WIDTH)
		{
			ballMove = BallMovement::downLeft;
		}
		break;
	}
}

void Ball::BallReset()
{
	if (ballY == 0)
	{
		ballY = HIGH / 2;
		ballX = WIDTH / 2;
		ballMove = BallMovement::down;
		playerScore++;
	}
	else if (ballY == HIGH)
	{
		ballY = HIGH / 2;
		ballX = WIDTH / 2;
		ballMove = BallMovement::down;
		enemyScore++;
	}
	if (enemyScore == 5)
	{
		gameOver = true;
	}
}
//Ball functions
//----------------------------------------------------------------------------------
//Platform functions
void Platform::EnemyPlatformMoving()
{
	if (enemyPlatformX < ballX)
	{
		enemyPlatformMove = PlatformMovement::right;
	}
	else
	{
		enemyPlatformMove = PlatformMovement::left;
	}
}

void Platform::PlatformTouchingTheWall()
{
	if (playerPlatformX == 0)
	{
		playerPlatformX++;
	}
	else  if (playerPlatformX == WIDTH - 1)
	{
		playerPlatformX--;
	}
	else if (enemyPlatformX == 0)
	{
		enemyPlatformMove = PlatformMovement::right;
	}
	else  if (enemyPlatformX == WIDTH - 1)
	{
		enemyPlatformMove = PlatformMovement::left;
	}
}

#endif // !GameRules
