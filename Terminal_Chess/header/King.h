#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	King(char color) : Figure(color) {}
	~King() {}

private:
	virtual char GetFigure() { return 'K'; }
	bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) override;

};

