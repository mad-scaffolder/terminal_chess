#pragma once
#include <iostream>

class Figure
{
public:
    Figure(char color) : color_(color) {}
    virtual ~Figure() {}
    virtual char GetFigure() = 0;
    char GetColor();
    bool IsLegalMove(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]);

private:
    virtual bool AreSquaresLegal(std::pair<int, int>, std::pair<int, int>, Figure* boardMove[8][8]) = 0;
    char color_;
};

