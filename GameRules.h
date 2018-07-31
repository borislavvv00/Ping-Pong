#pragma once
#ifndef GameRules
#include "ClassMap.h"
#include "ClassBall.h"
#include "ClassPlatform.h"

void Ball::TouchingPlayerPlatform()
{
	if (ball.y == playerPlatform.y - 1)
	{
		ballTrajectory = 1;
		if (ball.x == playerPlatform.x + 2)
		{
			ballDirection = BallDirection::up;
		}
		else if (ball.x == playerPlatform.x || ball.x == playerPlatform.x + 1)
		{
			ballDirection = BallDirection::upLeft;
		}
		else if (ball.x == playerPlatform.x + 3 || ball.x == playerPlatform.x + 4)
		{
			ballDirection = BallDirection::upRigth;
		}
	}
}

void Ball::TouchingEnemyPlatform()
{
	if (ball.y == enemyPlatform.y + 1)
	{
		ballTrajectory = 0;
		if (ball.x == enemyPlatform.x + 2)
		{
			ballDirection = BallDirection::down;
		}
		else if (ball.x == enemyPlatform.x || ball.x == enemyPlatform.x + 1)
		{
			ballDirection = BallDirection::downLeft;
		}
		else if (ball.x == enemyPlatform.x + 3 || ball.x == enemyPlatform.x + 4)
		{
			ballDirection = BallDirection::downRigth;
		}
	}
}

void Ball::ChooseDirection(int dir1, int dir2)
{
	if (ball.x == 1)
	{
		ballDirection = BallDirection(dir1);
	}
	else if (ball.x == WIDTH - 1)
	{
		ballDirection = BallDirection(dir2);
	}
}

void Ball::TouchingTheWall()
{
	switch (ballTrajectory)
	{
	case 0:
		ChooseDirection(2, 4);
		break;
	case 1:
		ChooseDirection(5, 3);
		break;
	}
}

void Ball::SetCoordinates()
{
	ball.y = HIGH / 2;
	ball.x = WIDTH / 2;
	ballDirection = BallDirection::down;
}
//Ball functions
//----------------------------------------------------------------------------------
//Platform functions
void Platform::EnemyPlatformMoveLogic()
{
	if (x < ball.x)
	{
		enemyDirection = PlatformDirection::right;
	}
	else
	{
		enemyDirection = PlatformDirection::left;
	}
}

void Platform::TouchingTheWall(PlatformDirection &dir)
{
	if (x == 1)
	{
		dir = PlatformDirection::right;
	}
	else  if (x == WIDTH - (platformWidth + 1))
	{
		dir = PlatformDirection::left;
	}
}
//Platform functions
//---------------------------------------------------------------------------
//Map functions
void Map::Reset()
{
	if (ball.y == 0)
	{
		playerPlatform.score++;
		playerPlatform.SetCoordinates(WIDTH / 2 - 2, HIGH - 3, playerDirection);
		enemyPlatform.SetCoordinates(WIDTH / 2 - 2, 3, enemyDirection);
		ball.SetCoordinates();
	}
	else if (ball.y == HIGH)
	{
		enemyPlatform.score++;
		playerPlatform.SetCoordinates(WIDTH / 2 - 2, HIGH - 3, playerDirection);
		enemyPlatform.SetCoordinates(WIDTH / 2 - 2, 3, enemyDirection);
		ball.SetCoordinates();
	}
}

#endif // !GameRules
