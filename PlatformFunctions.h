#pragma once
#ifndef PlatformFunctions
#include "ClassPlatform.h"

void Platform::BuildingPlatform(int color)
{
	for (int i = 0; i < platformWidth; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << platformSign;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

void Platform::SetCoordinates(int X, int Y, PlatformDirection &dir)
{
	x = X;
	y = Y;
	dir = PlatformDirection::stop;
}

#endif // !PlatformFunctions
