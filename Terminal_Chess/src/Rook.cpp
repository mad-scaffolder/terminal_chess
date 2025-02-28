#include "../header/Rook.h"

bool Rook::AreSquaresLegal(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
	if (pos.first == des.first)
	{
		// make sure that all invervening squares are empty I
		int colOffset = (des.second - pos.second > 0) ? 1 : -1;
		for (int checkCol = pos.second + colOffset;
			checkCol != des.second;
			checkCol += colOffset)
		{
			if (boardMove[pos.first][checkCol] != 0)
				return false;
		}
		return true;
	}
	else if (des.second == pos.second)
	{
		// make sure that all invervening squares are empty II
		int rowOffset = (des.first - pos.first > 0) ? 1 : -1;
		for (int checkRow = pos.first + rowOffset; checkRow != des.first; checkRow += rowOffset)
		{
			if (boardMove[checkRow][pos.second] != 0)
				return false;
		}
		return true;
	}
	return false;
}

