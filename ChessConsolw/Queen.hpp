#pragma once

#include "Piece.hpp"
#include "Color.hpp"

class Queen : public Piece
{
public:
	Queen(PieceList p, Color c, Location l)
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

	Color CurrentColor()
	{
		return color;
	}


private:
	PieceList piece;
	Color color;
	Location location;
};
