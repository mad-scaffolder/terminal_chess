#pragma once
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
public:
	Board();
	~Board();
	void PrintBoard();
	bool IsInCheck(char color);
	bool CanMove(char color);
	Figure* boardMove[8][8];
};

