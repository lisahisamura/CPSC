#if !defined(TICTACTOE_H)  
#define TICTACTOE_H  // Sentinel

#include <iostream>
#include <string>

class TicTacToeGame
{
    public:
        TicTacToeGame();
        virtual ~TicTacToeGame();
        void play();
        
    private:
        void displayGrid(); // function to display grid
        void initializeGrid(); // function to initialize grid
        std::tuple<int,int> promptForGridCoord(); // function to obtain the user move
        // std::tuple<int, int> findFirstUnoccupiedGridSquare(); // function to determine the computer's counter move
        std::tuple<int, int> pickGridSquareRandomly(); // function to determine the computer's counter move (randomly)
        bool checkForWin(); // check for a win
        bool checkForDraw(); // check for a draw (if board is filled up and no one won)
        
    private:
        char** pp_cGrid = nullptr; // pointer to (pointer to character)
};

#endif

