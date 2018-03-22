#pragma once
#ifndef ClassPlatform

class Platform
{
private:
	char platformSign;
	int platformWidth;
public:
	Platform()
	{
		platformSign = char(219);
		platformWidth = 5;
	}
	~Platform() {}
	void BuildingPlatform(int);
	void EnemyPlatformMoving();
	void PlatformTouchingTheWall();
};

#endif // !ClassPlatform
