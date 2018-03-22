#pragma once
#ifndef MapFunctions
#include <iostream>
#include "GameSetUp.h"

using namespace std;

void Map::BuildingMap()
{
	for (int i = 0; i < WIDTH; i++)
	{
		cout << wallSign;			//up border
	}
	cout << endl;
	//----------------------------------------------
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0 || j == WIDTH - 1)
			{
				cout << wallSign;   //left and rigth borders
			}
			//---------------------------------------------------------------
			else if (i == playerPlatformY && j == playerPlatformX)
			{
				playerPlatform.BuildingPlatform(10); //player platform position
			}
			else if (i == enemyPlatformY && j == enemyPlatformX)
			{
				enemyPlatform.BuildingPlatform(12); //enemy platform position
			}
			else if (i == ballY && j == ballX)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << ball.ballSign;											//ball position
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if ((i == playerPlatformY || i == enemyPlatformY) && (j >= WIDTH / 2 - 2 && j <= WIDTH / 2 + 2))
			{
				continue; //remove redundant spaces
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	//----------------------------------------
	for (int i = 0; i < WIDTH; i++)
	{
		cout << wallSign;			//down border
	}
	cout << endl;
	cout << "Player score: " << playerScore << "		Enemy score: " << enemyScore << endl;
}

#endif // !MapFunctions
