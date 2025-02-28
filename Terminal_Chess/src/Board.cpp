#include "../header/Board.h"
#include <iostream>

Board::Board()
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
			boardMove[row][col] = 0;
	}

	// allocate and place black pieces
	for (int col = 0; col < 8; ++col)
	{
		boardMove[6][col] = new Pawn('B');
	}
	boardMove[7][0] = new Rook('B');
	boardMove[7][1] = new Knight('B');
	boardMove[7][2] = new Bishop('B');
	boardMove[7][3] = new Queen('B');
	boardMove[7][4] = new King('B');
	boardMove[7][5] = new Bishop('B');
	boardMove[7][6] = new Knight('B');
	boardMove[7][7] = new Rook('B');

	// allocate and place white pieces
	for (int col = 0; col < 8; ++col)
	{
		boardMove[1][col] = new Pawn('W');
	}

	boardMove[0][0] = new Rook('W');
	boardMove[0][1] = new Knight('W');
	boardMove[0][2] = new Bishop('W');
	boardMove[0][3] = new Queen('W');
	boardMove[0][4] = new King('W');
	boardMove[0][5] = new Bishop('W');
	boardMove[0][6] = new Knight('W');
	boardMove[0][7] = new Rook('W');
}

Board::~Board()
{
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			delete boardMove[row][col];
			boardMove[row][col] = 0;
		}
	}
}

void Board::PrintBoard()
{
	const int squareHeight = 3;
	const int squareWidth = 4;

	for (int row = 0; row < 8 * squareHeight; ++row)
	{
		int squareRow = row / squareHeight;
		// print side border with numbering
		if (row % 3 == 1)
		{
			std::cout << '-' << (char)('1' + 7 - squareRow) << '-';
		}
		else
		{
			std::cout << "---";
		}
		// print the chess board
		for (int col = 0; col < 8 * squareWidth; ++col)
		{
			int squareCol = col / squareWidth;
			if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && boardMove[7 - squareRow][squareCol] != 0)
			{
				if ((col % 4) == 1)
				{
					std::cout << boardMove[7 - squareRow][squareCol]->GetColor();
				}
				else
				{
					std::cout << boardMove[7 - squareRow][squareCol]->GetFigure();
				}
			}
			else
			{
				if ((squareRow + squareCol) % 2 == 1)
				{
					std::cout << ' ';
				}
				else
				{
					std::cout << '*';
				}
			}
		}
		std::cout << std::endl;
	}
	// print the bottom border with numbers
	for (int row = 0; row < squareHeight; ++row)
	{
		if (row % 3 == 1)
		{
			std::cout << "---";
			for (int col = 0; col < 8 * squareWidth; ++col)
			{
				int squareCol = col / squareWidth;
				if ((col % 4) == 1)
				{
					std::cout << (squareCol + 1);
				}
				else
				{
					std::cout << '-';
				}
			}
			std::cout << std::endl;
		}
		else
		{
			for (int col = 1; col < 9 * squareWidth; ++col)
			{
				std::cout << '-';
			}
			std::cout << std::endl;
		}
	}
}

bool Board::IsInCheck(char color)
{
	// find the king
	std::pair<int, int> kingPlace;
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (boardMove[row][col] != 0)
			{
				if (boardMove[row][col]->GetColor() == color)
				{
					if (boardMove[row][col]->GetFigure() == 'K')
					{
						kingPlace.first = row;
						kingPlace.second = col;
					}
				}
			}
		}
	}

	// run through the opponent's pieces and see if any can take the king
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (boardMove[row][col] != 0)
			{
				std::pair<int, int> figurePos(row, col);
				if (boardMove[row][col]->GetColor() != color)
				{
					if (boardMove[row][col]->IsLegalMove(figurePos, kingPlace, boardMove))
						return true;
				}
			}
		}
	}

	return false;
}

bool Board::CanMove(char color)
{
	std::pair<int, int> figurePos, figureDes;
	// run through all pieces
	for (int row = 0; row < 8; ++row)
	{
		for (int col = 0; col < 8; ++col)
		{
			if (boardMove[row][col] != 0)
			{
				figurePos.first = row;
				figurePos.second = col;
				// if it is a piece of the current player, see if it has a legal move
				if (boardMove[row][col]->GetColor() == color)
				{
					for (int moveRow = 0; moveRow < 8; ++moveRow)
					{
						for (int moveCol = 0; moveCol < 8; ++moveCol)
						{
							figureDes.first = moveRow;
							figureDes.second = moveCol;
							if (boardMove[row][col]->IsLegalMove(figurePos, figureDes, boardMove))
							{
								// make move and check whether king is in check
								Figure* temp = boardMove[moveRow][moveCol];
								boardMove[moveRow][moveCol] = boardMove[row][col];
								boardMove[row][col] = 0;
								bool boolCanMove = !IsInCheck(color);

								// undo the move
								boardMove[row][col] = boardMove[moveRow][moveCol];
								boardMove[moveRow][moveCol] = temp;

								if (boolCanMove)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}
