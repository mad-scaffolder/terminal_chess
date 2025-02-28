#include "../header/Figure.h"

char Figure::GetColor()
{
	return color_;
}

bool Figure::IsLegalMove(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
    Figure* dest = boardMove[des.first][des.second];
    if ((dest == 0) || (color_ != dest->GetColor()))
        return AreSquaresLegal(pos, des, boardMove);

    return false;
}
