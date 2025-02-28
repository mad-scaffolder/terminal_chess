#include "../header/Queen.h"

bool Queen::AreSquaresLegal(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
	if (pos.first == des.first)
	{
		// make sure that all invervening squares are empty
		int colOffset = (des.second - pos.second > 0) ? 1 : -1;
		for (int checkCol = pos.second + colOffset; checkCol != des.second; checkCol = checkCol + colOffset)
		{
			if (boardMove[pos.first][checkCol] != 0)
				return false;
		}
		return true;
	}
	else if (pos.second == des.second)
	{
		// make sure that all invervening squares are empty
		int rowOffset = (des.first - pos.first > 0) ? 1 : -1;
		for (int checkRow = pos.first + rowOffset; checkRow != des.first; checkRow += rowOffset)
		{
			if (boardMove[checkRow][pos.second] != 0)
				return false;
		}
		return true;
	}
	else if ((des.second - pos.second == des.first - pos.first) ||
		(des.second - pos.second == pos.first - des.first))
	{
		// make sure that all invervening squares are empty
		int rowOffset = (des.first - pos.first > 0) ? 1 : -1;
		int colOffset = (des.second - pos.second > 0) ? 1 : -1;
		int checkRow;
		int checkCol;
		for (checkRow = pos.first + rowOffset, checkCol = pos.second + colOffset;
			checkRow != des.first;
			checkRow += rowOffset, checkCol += colOffset)
		{
			if (boardMove[checkRow][checkCol] != 0)
				return false;
		}
		return true;
	}
	return false;
}
