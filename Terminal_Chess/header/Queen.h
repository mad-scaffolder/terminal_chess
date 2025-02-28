#pragma once
#include "Figure.h"

class Queen : public Figure
{
public:
	Queen(char color) : Figure(color) {}
	~Queen() {}

private:
	virtual char GetFigure() { return 'Q'; }
	bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) override;

};

