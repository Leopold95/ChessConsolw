#pragma once

#include <exception>

class Location
{
public:
	Location() {}

	Location(int x, int y)
	{
		this->x = x;
		if (x <= 1 && x >= 8) throw new std::exception("x is nt valid");

		this->y = y;
		if (y <= 1 && y >= 8) throw new std::exception("y is nt valid");
	}

	friend bool operator== (const Location& loc1, const Location& loc2)
	{
		return (loc1.x == loc2.x && loc1.y == loc2.y);
	}

	int x = 0;
	int y = 0;
};