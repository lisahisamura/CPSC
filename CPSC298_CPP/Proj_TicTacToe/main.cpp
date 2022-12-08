/// @file main.cpp
/// @brief Main function for Tic Tac Toe Game.
/// @author Lisa Hisamura hisamura@chapman.edu
#include <iostream>
#include <string>
#include <tuple>
#include "TicTacToe.h"

int main()
{
    TicTacToeGame* p_game = new TicTacToeGame();
   
    p_game -> play();

    delete p_game;

}