#pragma once

#include "PieceList.hpp"
#include "Location.hpp"
#include "Color.hpp"

class Piece
{
public:
	virtual PieceList& CurrentPiece() = 0;
	virtual Location& CurrentLocation() = 0;
	virtual Color CurrentColor() = 0;
	virtual bool IsAlive() = 0;
	virtual void Kill() = 0;
};
