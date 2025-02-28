#pragma once
#include "Figure.h"

class Rook : public Figure
{
public:
	Rook(char color) : Figure(color) {}
	~Rook() {}

private:
	virtual char GetFigure() { return 'R'; }
	bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) override;
};

