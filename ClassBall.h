#pragma once
#ifndef ClassBall
#include "GameSetUp.h"

class Ball 
{
private:
	int x, y;
	void ChooseDirection(int dir1, int dir2);//dir = direction
public:
	char ballSign;
	Ball()
	{
		ballSign = '.';
	}
	void TouchingPlayerPlatform();
	void TouchingEnemyPlatform();
	void TouchingTheWall();
	void SetCoordinates();
	void MovementDescription();
	friend class Map;
	friend class Platform;
};

Ball ball;

#endif // !ClassBall
