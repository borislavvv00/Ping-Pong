#pragma once
#ifndef MapFunctions
#include "ClassMap.h"
#include "ClassBall.h"
#include "ClassPlatform.h"
#include "PlatformFunctions.h"

void Map::BuildHorizontalBorder()
{
	for (int i = 0; i < WIDTH; i++)
	{
		cout << wallSign;	
	}
	cout << endl;
}

void Map::BuildingMap()
{
	BuildHorizontalBorder();//up border
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
			else if (i == playerPlatform.y && j == playerPlatform.x)
			{
				playerPlatform.BuildingPlatform(10); //player platform position
			}
			else if (i == enemyPlatform.y && j == enemyPlatform.x)
			{
				enemyPlatform.BuildingPlatform(12); //enemy platform position
			}
			else if (i == ball.y && j == ball.x)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << ball.ballSign;	//ball position
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if ((i == playerPlatform.y || i == enemyPlatform.y) && (j >= playerPlatform.x && j <= playerPlatform.x + playerPlatform.platformWidth - 1))
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
	BuildHorizontalBorder();//down border

	cout << "Player score: " << playerPlatform.score << "		Enemy score: " << enemyPlatform.score << endl;
}

#endif // !MapFunctions
