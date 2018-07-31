#pragma once
#ifndef ClassMap
#include "GameSetUp.h"

class Map
{
private:
	char wallSign;
	void BuildHorizontalBorder();
public:	
	Map()
	{
		wallSign = char(219);
	}
	void BuildingMap();
	void Reset();
};

#endif // !ClassMap
