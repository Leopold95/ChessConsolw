#pragma once

#include <exception>
#include "BugLogger.h"

struct Location
{
public:
	Location() {}

	Location(int xx, int yy)
	{

		if (xx < 1) xx = 1;
		if (xx > 8) xx = 8;
		if (yy < 1) yy = 1;
		if (yy > 8) yy = 8;

		x = xx;
		y = yy;
	}
	Location(short xx, short yy)
	{

		if (xx < 1) xx = 1;
		if (xx > 8) xx = 8;
		if (yy < 1) yy = 1;
		if (yy > 8) yy = 8;

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