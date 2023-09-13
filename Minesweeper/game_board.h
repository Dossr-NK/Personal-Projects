#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <iostream>
#include <vector>

namespace GameBoard {

struct Cell {
    bool is_mine;
    std::string status;
    bool is_flagged;
    bool is_revealed;
};

class GameBoard {
    public:
        GameBoard(int dimensions, int difficulty) : dimensions_(dimensions), difficulty_(difficulty) {
            mine_count_ = GameBoard::GameBoard::calculateMines();
            board_ = GameBoard::GameBoard::createGameBoard();
            GameBoard::GameBoard::placeMines();
        }

        std::vector<std::vector<Cell>> createGameBoard();
        int calculateMines();
        void placeMines();
        void printBoard();

    private:
        std::vector<std::vector<Cell>> board_;
        int dimensions_;
        int difficulty_;
        int mine_count_;
};

}  // namespace GameBoard

#endif // GAME_BOARD_H