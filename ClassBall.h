#pragma once
#ifndef ClassBall

class Ball 
{
public:
	char ballSign;
	Ball()
	{
		ballSign = '.';
	}
	~Ball() {}
	void BallTouchingPlayerPlatform();
	void BallTouchingEnemyPlatform();
	void BallTouchingTheWall();
	void BallReset();
};

#endif // !ClassBall
