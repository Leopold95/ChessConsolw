#pragma once

#include "Piece.hpp"

class King : public  Piece
{
public:
	King(PieceList p, Color c, Location l, bool a)
	{
		piece = p;
		color = c;
		location = l;
		isAlive = a;
	}

	PieceList& CurrentPiece() override
	{
		return piece;
	}

	Location& CurrentLocation() override
	{
		return location;
	}
	 
	Color CurrentColor() override
	{
		return color;
	}
	bool IsAlive() override
	{
		return isAlive;
	}

	void Kill() override
	{
		isAlive = false;
	}


private:
	PieceList piece;
	Color color;
	Location location;
	bool isAlive;
};