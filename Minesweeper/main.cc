#include <iostream>
#include <ctime>

#include "game_board.h"
#include "game_logic.h"

using ::GameBoard::GameBoard;
using ::GameBoard::Cell;

int main() {
    std::srand(std::time(nullptr));

    std::cout << "What size game board would you like (8-50? " << std::endl;
    int dimensions;
    std::cin >> dimensions;
    
    std::cout << "What difficulty would you like (0-4)? " << std::endl;
    int difficulty;
    std::cin >> difficulty;

    GameBoard::GameBoard game_board(dimensions, difficulty);
    game_board.printBoard();

    return 0;
}