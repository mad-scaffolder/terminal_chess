#include "../header/Pawn.h"

bool Pawn::AreSquaresLegal(std::pair<int, int> pos, std::pair<int, int> des, Figure* boardMove[8][8])
{
	Figure* dest = boardMove[des.first][des.second];
	if (dest == 0)
	{
		// Destination square is unoccupied
		if (pos.second == des.second)
		{
			if (GetColor() == 'W')
			{
				if (des.first == pos.first + 1)
					return true;
			}
			else
			{
				if (des.first == pos.first - 1)
					return true;
			}
		}
	}
	else
	{
		// Destination holds piece of opposite color
		if ((pos.second == des.second + 1) || (pos.second == des.second - 1))
		{
			if (GetColor() == 'W')
			{
				if (des.first == pos.first + 1)
					return true;
			}
			else
			{
				if (des.first == pos.first - 1)
					return true;
			}
		}
	}
	return false;
}
