#include "../header/Game.h"
#include <iostream>
#include <limits>

void Game::Start()
{
    std::cout << "Console chess game." << std::endl <<
        "Enter 999 to exit." << std::endl;
    exitCode = false;
    do
    {
        if (exitCode)
            break;

        GetNextMove(gameBoard_.boardMove);
        AlternateTurn();
    } while (!IsGameOver());

    std::cout << "The last move:" << std::endl;
    gameBoard_.PrintBoard();
    std::cout << std::endl;
}

void Game::GetNextMove(Figure* boardMove[8][8])
{
    bool boolValidMove = false;
    do
    {
        gameBoard_.PrintBoard();

        // get input and convert to coordinates
        int startMove;
        int startRow;
        int startCol;

        int endMove;
        int endRow;
        int endCol;

        std::cout << turnOf_ << "'s Move: ";
        std::cin >> startMove;
        std::cout << "To: ";
        std::cin >> endMove;

        while (std::cin.fail() || startMove > 1000 || startMove < -1000 || endMove > 1000 || endMove < -1000)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input! Enter number coordinates (num of 2 digits)." << std::endl;
            std::cout << turnOf_ << "'s Move: ";
            std::cin >> startMove;
            std::cout << "To: ";
            std::cin >> endMove;
        }

        if (startMove == 999 || endMove == 999)
        {
            std::cout << "You've entered the exit game code 999.\nHave a nice day!" << std::endl;
            exitCode = true;
            exit(0);
        }

        startRow = (startMove / 10) - 1;
        startCol = (startMove % 10) - 1;
        endRow = (endMove / 10) - 1;
        endCol = (endMove % 10) - 1;
        std::pair<int, int> figurePos(startRow, startCol), figureDes(endRow, endCol);

        // check that the indices are in range
        // and that the source and destination are different
        if ((startRow >= 0 && startRow <= 7) && (startCol >= 0 && startCol <= 7) && (endRow >= 0 && endRow <= 7) && (endCol >= 0 && endCol <= 7))
        {
            // additional checks in here
            Figure* currentFigure = boardMove[startRow][startCol];
            // check that the piece is the correct color
            if ((currentFigure != 0) && (currentFigure->GetColor() == turnOf_))
            {
                // check that the destination is a valid destination
                if (currentFigure->IsLegalMove(figurePos, figureDes, boardMove))
                {
                    // make the move
                    Figure* temp = boardMove[endRow][endCol];
                    boardMove[endRow][endCol] = boardMove[startRow][startCol];
                    boardMove[startRow][startCol] = 0;
                    // make sure that the current player is not in check
                    if (!gameBoard_.IsInCheck(turnOf_))
                    {
                        delete temp;
                        boolValidMove = true;
                    }
                    else
                    { // undo the last move
                        boardMove[startRow][startCol] = boardMove[endRow][endCol];
                        boardMove[endRow][endCol] = temp;
                    }
                }
            }
        }
        if (!boolValidMove)
        {
            std::cout << "Invalid move!" << std::endl;
        }
    } while (!boolValidMove);
}

void Game::AlternateTurn() { turnOf_ = (turnOf_ == 'W') ? 'B' : 'W'; }

bool Game::IsGameOver()
{
    // check that the current player can move;
    // if not, we have a draw or checkmate
    bool boolCanMove(false);
    boolCanMove = gameBoard_.CanMove(turnOf_);
    if (!boolCanMove)
    {
        if (gameBoard_.IsInCheck(turnOf_))
        {
            AlternateTurn();
            std::cout << "Checkmate!" << std::endl;
            if (turnOf_ == 'W')
                std::cout << "Whites is the winner!" << std::endl;
            else
                std::cout << "Blacks is the winner!" << std::endl;
        }
        else
        {
            std::cout << "Draw!" << std::endl;
        }
    }

    return !boolCanMove;
}
