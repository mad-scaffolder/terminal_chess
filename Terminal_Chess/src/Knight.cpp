#include "../header/Knight.h"

bool Knight::AreSquaresLegal(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
	// destination square is unoccupied or occupied by opposite color
	if ((pos.second == des.second + 1) || (pos.second == des.second - 1))
	{
		if ((pos.first == des.first + 2) || (pos.first == des.first - 2))
			return true;
	}
	if ((pos.second == des.second + 2) || (pos.second == des.second - 2))
	{
		if ((pos.first == des.first + 1) || (pos.first == des.first - 1))
			return true;
	}
	return false;
}
