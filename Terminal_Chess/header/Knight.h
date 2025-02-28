#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
	Knight(char color) : Figure(color) {}
	~Knight() {}

private:
	virtual char GetFigure() { return 'N'; }
	bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) override;

};

