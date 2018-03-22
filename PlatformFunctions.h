#pragma once
#ifndef PlatformFunctions
#include <iostream>
#include <Windows.h>
#include "ClassPlatform.h"

using namespace std;

void Platform::BuildingPlatform(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	for (int i = 0; i < platformWidth; i++)
	{
		cout << platformSign;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

#endif // !PlatformFunctions
