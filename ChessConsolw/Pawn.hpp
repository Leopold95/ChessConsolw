#pragma once

#include "Piece.hpp"

class Pawn : public Piece
{
public:
	Pawn(PieceList p, Color c, Location l, bool a)
	{
		piece = p;
		color = c;
		location = l;
		isAlive = a;
	}



	PieceList CurrentPiece() override
	{
		return piece;
	}

	Location CurrentLocation() override
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

	void SetAlive(bool b)
	{
		isAlive = b;
	}


private:
	PieceList piece;
	Color color;
	Location location;
	bool isAlive;
};
