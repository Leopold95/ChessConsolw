#pragma once

#include "Piece.hpp"
#include "Color.hpp"

class Pawn : public Piece
{
public:
	Pawn(PieceList p, Color c, Location l)
	{
		piece = p;
		color = c;
		location = l;
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


private:
	PieceList piece;
	Color color;
	Location location;
};
