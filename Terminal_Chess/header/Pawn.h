#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
	Pawn(char color) : Figure(color) {}
	~Pawn() {}

private:
	virtual char GetFigure() { return 'P'; }
	bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) override;
};

