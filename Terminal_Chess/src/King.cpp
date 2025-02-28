#include "../header/King.h"

bool King::AreSquaresLegal(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
	int calcRow = des.first - pos.first;
	int calcDest = des.second - pos.second;
	if (((calcRow >= -1) && (calcRow <= 1)) &&
		((calcDest >= -1) && (calcDest <= 1)))
	{
		return true;
	}
	return false;
}
