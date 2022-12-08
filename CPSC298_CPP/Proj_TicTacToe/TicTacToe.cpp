/// @file TicTacToe.cpp
/// @brief Implements a tic-tac-toe game between the user player and the computer player.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include "TicTacToe.h"

#define DIAG




TicTacToeGame::TicTacToeGame()
{
    this->pp_cGrid = new char* [3]; // array of three pointers to char

    for (int iRow = 0; iRow < 3; ++iRow)
    {
        pp_cGrid[iRow] = new char[3]; // array notation
    }

    for (int iColumn = 0; iColumn < 3; ++iColumn)
    {
        pp_cGrid[iColumn] = new char[3];
    }

}

TicTacToeGame::~TicTacToeGame()
{
    for (int iRow = 0; iRow < 3; ++iRow)
    {
        delete[] pp_cGrid[iRow]; // delete the arrays of 3 characters first
    }

    delete[] pp_cGrid; // delete array of three pointers to character
    pp_cGrid = nullptr; // to indicate it's not valid anymore
}

// set grid to all tildes
void TicTacToeGame::initializeGrid()
{
    for (int iRow = 0; iRow < 3; iRow++)
	{
		for (int iColumn = 0; iColumn < 3; iColumn++ )
		{
			
			this->pp_cGrid[iRow][iColumn] = '~';

		}
	}
}

// display the 3x3 grid
void TicTacToeGame::displayGrid()
{
    for (int iRow = 0; iRow < 3; iRow++) {
        for (int iColumn = 0; iColumn < 3; iColumn++) {
            std::cout << this-> pp_cGrid[iRow][iColumn] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


std::tuple<int,int> TicTacToeGame::promptForGridCoord()
{

    int iRow = 0;
    int iColumn = 0;

    bool bGridSquareValid = false;

    while (!bGridSquareValid)
    {
        std::cout << "Please enter grid row number: " << std::endl;
        std::cin >> iRow;
        while (iRow < 0 || iRow > 2) {
            std::cout << "Please enter a valid grid row number: " << std::endl;
            std::cin >> iRow;
        }

        std::cout << "Please enter grid column number: " << std::endl;
        std::cin >> iColumn;
        while (iColumn < 0 || iColumn > 2) {
            std::cout << "Please enter a valid grid column number." << std::endl;
            std::cin >> iColumn;
        }

        if (this -> pp_cGrid[iRow][iColumn] == '~')
        {
            bGridSquareValid = true;
        } else {
            std::cout << "The grid square " << this -> pp_cGrid[iRow][iColumn] << " is already taken." << std::endl;
        }
    }

    std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iColumn);
    return tupleCoord;

}

        
    
// std::tuple<int, int> TicTacToeGame::findFirstUnoccupiedGridSquare()
// {
//     // no extra credit
//     int iRowUnoccupied = -1;
//     int iColumnUnoccupied = -1;

//     bool bFound = false;

//     for (int iRow = 0; (iRow < 3) && !bFound; iRow++)
//     {
//         for (int iColumn = 0; (iColumn < 3) && !bFound; iColumn++) {
//             if (this -> pp_cGrid[iRow][iColumn] == '~')
//             {
//                 iRowUnoccupied = iRow;
//                 iColumnUnoccupied = iColumn;
//                 bFound = true;
//             }
//         }
//     }
//     std::tuple<int,int> tupleUnoccupiedGridSquare(iRowUnoccupied, iColumnUnoccupied);
//     return tupleUnoccupiedGridSquare;

// }



std::tuple<int,int> TicTacToeGame::pickGridSquareRandomly()
{

	int iRowUnoccupied = -1;
    int iColumnUnoccupied = -1;

    bool bFound = false;

    std::random_device randomDevice;

	std::default_random_engine randomNumberGenerator(randomDevice());

    while (!bFound) {
        std::uniform_int_distribution<int> uniformIntegerDistributionRows(0, 2);
        iRowUnoccupied = uniformIntegerDistributionRows(randomNumberGenerator);

        std::uniform_int_distribution<int> uniformIntegerDistributionColumns(0, 2);
        iColumnUnoccupied = uniformIntegerDistributionColumns(randomNumberGenerator);

        if (pp_cGrid[iRowUnoccupied][iColumnUnoccupied] == '~')
        {
            bFound = true;
        }
    }

    std::tuple<int,int> tupleUnoccupiedGridSquare(iRowUnoccupied, iColumnUnoccupied);
    return tupleUnoccupiedGridSquare;

#if defined(DIAG)
	std::cout << "Square Location: Row: " << iRowUnoccupied << "; Column: " << iColumnUnoccupied << std::endl;
#endif

}



bool TicTacToeGame::checkForWin()
{

    // checkForWin pt.1 check for three Os or Xs in a row
    bool bWin = false;

    for (int iRow = 0; (iRow < 3) && !bWin; iRow++)
    {
        if (this->pp_cGrid[iRow][0] != '~')
        {
            if ((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) && (this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][2]))
            {
                bWin = true;
                std::cout << "Winner: " << this->pp_cGrid[iRow][0] << "!" << std::endl;
            }
        }
    }

    // pt.2 check for three Os or Xs in a column
    for (int iColumn = 0; (iColumn < 3) && !bWin; iColumn++)
    {
        if (this->pp_cGrid[iColumn][0] != '~')
        {
            if ((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) && (this->pp_cGrid[0][iColumn] == this->pp_cGrid[2][iColumn]))
            {
                bWin = true;
                std::cout << "Winner: " << this->pp_cGrid[0][iColumn] << "!" << std::endl;
            }
        }
    }

    // pt. 3 check first diagonal
    if (this->pp_cGrid[0][0] != '~')
    {
        if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][0] == this->pp_cGrid[2][2]))
        {
            bWin = true;
            std::cout << "Winner: " << this->pp_cGrid[0][0] << "!" << std::endl;
        }
    }

    // pt.4 check second diagonal
    if (this->pp_cGrid[0][2] != '~')
    {
        if ((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) && (this->pp_cGrid[0][2] == this->pp_cGrid[2][0]))
        {
            bWin = true;
            std::cout << "Winner: " << this->pp_cGrid[0][2] << "!" << std::endl;
        }
    }

    return bWin;
}



bool TicTacToeGame::checkForDraw()
{
    // if board is filled up and no one won, it's a draw
    bool bContinue = false;
    
    for (int iRow = 0; iRow < 3; iRow++) {
        for (int iColumn = 0; iColumn < 3; iColumn++) {
            if (this-> pp_cGrid[iRow][iColumn] != 'X' && this->pp_cGrid[iRow][iColumn] != 'O') {
                bContinue = true;
            }
        }
    }

    return !bContinue;
}
        


void TicTacToeGame::play()
{
    bool bWin = false;
    bool bDraw = false;
    
    this->initializeGrid();
    
    std::cout << "Tic Tac Toe" << std::endl;
    std::cout << "The top row is row number 0. the middle row number 1, and the bottom row is row number 2." << std::endl;
    std::cout << "The left column is column number 0, the middle column number 1, and the right column is column number 2." << std::endl;
    
    this->displayGrid();

    while (!bWin && !bDraw) {
        int iRow = 0;
        int iColumn = 0;
        
        std::tie(iRow, iColumn) = promptForGridCoord();
        this->pp_cGrid[iRow][iColumn] = 'X';
        
        displayGrid();
        bWin = checkForWin();
        if (!bWin) {
                bDraw = checkForDraw();
        }

        if (!bWin && !bDraw)
        {
            std::tie(iRow, iColumn) = pickGridSquareRandomly();
            std::cout << iRow << std::endl;
            std::cout << iColumn << std::endl;
            this->pp_cGrid[iRow][iColumn] = 'O';
            displayGrid();
            bWin = checkForWin();
            if (!bWin) {
                bDraw = checkForDraw();
            }
        }

        if (bDraw)
        {
            std::cout << "Draw!" << std::endl;
        }
    }

    std::cout << "Game over." << std::endl;

    return;
}


// // // Main game loop logic
// // // while (!Win && !Draw) {
// //     // Get user move (row/column)
// //     // Check for win or draw
// //     // if not win or draw {
// //         // get computer move
// //         // check for win or draw
// //     // }
// // // }
