#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
	Bishop(char color) : Figure(color) {}
	~Bishop() {}

private:
	virtual char GetFigure() { return 'B'; }
	bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) override;

};

