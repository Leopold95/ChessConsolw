#pragma once

#include "Piece.hpp"

class EmptyPiece : public Piece
{
	PieceList CurrentPiece() override
	{
	}

	Location CurrentLocation() override
	{
	}

	Color CurrentColor() override
	{
	}

	bool IsAlive() override
	{
	}

	void Kill() override
	{
	}
};