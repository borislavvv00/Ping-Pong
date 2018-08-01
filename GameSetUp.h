#pragma once
#ifndef GameSetUp
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <bitset>
#define WIDTH 40
#define HIGH 20

using namespace std;

bool isGameOver = false;
bitset<1> ballTrajectory;//0-hit by enemy; 1-hit by player

enum class BallDirection
{
	down, up, downRigth, upLeft, downLeft, upRigth
};

enum class PlatformDirection
{
	stop, left, right
};

BallDirection ballDirection;
PlatformDirection enemyDirection;
PlatformDirection playerDirection;

void ClearScreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

#endif // !GameSetUp
