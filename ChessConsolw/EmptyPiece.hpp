#pragma once

#include "Piece.hpp"

class EmptyPiece : public Piece
{
public:
	PieceList& CurrentPiece() override
	{
		return type;
	}

	Location& CurrentLocation() override
	{
		return loc;
	}

	Color CurrentColor() override
	{
		return Color::None;
	}

	bool IsAlive() override
	{
		return false;
	}

	void Kill() override
	{
	}

private:
	PieceList type;
	Location loc;
	Color col;
};