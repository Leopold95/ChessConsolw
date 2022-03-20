#pragma once

#include <exception>

struct Location
{
public:
	Location() {}

	Location(int xx, int yy)
	{
		if (xx < 1 || xx > 8) throw new std::exception("x is not valid");
		if (yy < 1 || yy > 8) throw new std::exception("y is not valid");

		x = xx;
		y = yy;
	}

	friend bool operator== (const Location& loc1, const Location& loc2)
	{
		return (loc1.x == loc2.x && loc1.y == loc2.y);
	}

	int x = 1;
	int y = 1;
};