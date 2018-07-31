#pragma once
#ifndef GameMovement
#include "ClassBall.h"
#include "ClassPlatform.h"

void Platform::GetKeyboardCommands() //player move
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			playerDirection = PlatformDirection::left;
			break;
		case 'd':
			playerDirection = PlatformDirection::right;
			break;
		}
	}
}

void Platform::MovementDescription(PlatformDirection movement)
{
	switch (movement)
	{
	case PlatformDirection::left:
		x--;
		break;
	case PlatformDirection::right:
		x++;
		break;
	}
}

void Ball::MovementDescription()
{
	switch (ballDirection)
	{
	case BallDirection::down:
		y++;
		break;
	case BallDirection::up:
		y--;
		break;
	case BallDirection::upLeft:
		x--;
		y--;
		break;
	case BallDirection::upRigth:
		x++;
		y--;
		break;
	case BallDirection::downLeft:
		x--;
		y++;
		break;
	case BallDirection::downRigth:
		x++;
		y++;
		break;
	}
}

#endif // !GameMovement
