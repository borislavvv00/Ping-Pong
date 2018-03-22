#pragma once
#ifndef GameSetUp
#include <Windows.h>
#include "ClassMap.h"
#include "ClassBall.h"
#include "PlatformFunctions.h"

void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

bool gameOver = false;
bool ballTrajectory;//0-hit by enemy; 1-hit by player
Platform enemyPlatform;
Platform playerPlatform;
Ball ball;
int playerScore = 0;
int enemyScore = 0;
int enemyPlatformX = WIDTH / 2 - 2;
int enemyPlatformY = 3;
int playerPlatformX = WIDTH / 2 - 2;
int playerPlatformY = HIGH - 3;
int ballX = WIDTH / 2;
int ballY = HIGH / 2;

#endif // !GameSetUp
