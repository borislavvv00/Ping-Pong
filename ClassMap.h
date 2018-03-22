#pragma once
#ifndef ClassMap
#define WIDTH 40
#define HIGH 20

class Map
{
private:
	char wallSign;
public:	
	Map()
	{
		wallSign = char(219);
	}
	~Map() {}
	void BuildingMap();
};

#endif // !ClassMap
