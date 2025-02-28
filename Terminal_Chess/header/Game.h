#pragma once
#include <iostream>
#include "Figure.h"
#include "Board.h"

class Game
{
public:
	Game() : turnOf_('W') {}
	~Game() {}
	void Start();
	bool IsGameOver();

protected:
	void GetNextMove(Figure* boardMove[8][8]);
	void AlternateTurn();
	bool exitCode;

private:
	Board gameBoard_;
	char turnOf_;
};

