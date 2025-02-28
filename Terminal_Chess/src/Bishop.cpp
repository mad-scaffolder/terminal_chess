#include "../header/Bishop.h"

bool Bishop::AreSquaresLegal(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
	if ((des.second - pos.second == des.first - pos.first) || 
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
