#include "game_board.h"

#include <vector>

namespace GameBoard {

int GameBoard::calculateMines() {
    int total_cells = dimensions_ * dimensions_;
    double mine_percentage;
    switch (difficulty_) {
        case 0: // Easy difficulty
            mine_percentage = static_cast<double>(rand() % 6 + 10) / 100;
            std::cout << "Difficulty: Easy" << std::endl;
            break;
        case 1: // Medium difficulty
            mine_percentage = static_cast<double>(rand() % 6 + 15) / 100;
            std::cout << "Difficulty: Medium" << std::endl;
            break;
        case 2: // Hard difficulty
            mine_percentage = static_cast<double>(rand() % 6 + 20) / 100;
            std::cout << "Difficulty: Hard" << std::endl;
            break;
        case 3: // Expert difficulty
            mine_percentage = static_cast<double>(rand() % 6 + 25 / 100);
            std::cout << "Difficulty: Expert" << std::endl;
            break;
        case 4: // Extreme difficulty
            mine_percentage = static_cast<double>(rand() % 6 + 30) / 100;
            std::cout << "Difficulty: Extreme" << std::endl;
            break;
        default: // Default difficulty if no difficulty is selected
            mine_percentage = static_cast<double>(rand() % 6 + 15) / 100;
            std::cout << "Difficulty: Default" << std::endl;
            break;
    }
    return static_cast<int>(total_cells * mine_percentage);
}

std::vector<std::vector<Cell>> GameBoard::createGameBoard() {
    auto board = std::vector<std::vector<Cell>>(dimensions_, std::vector<Cell>(dimensions_, {false, " - "}));
    return board;
}

void GameBoard::placeMines() {
    int mines_placed = 0;
    while (mines_placed < mine_count_) {
        int row = rand() % board_.size();
        int col = rand() % board_.size();
        if (!board_[row][col].is_mine) {
            board_[row][col].is_mine = true;
            ++mines_placed;
        }
    }
}

void GameBoard::printBoard() {
    std::cout << "Number of Mines: " << mine_count_ << std::endl;
    for (int r = 0; r < board_.size(); ++r) {
        for (int c = 0; c < board_.size(); ++c) {
            std::cout << board_[r][c].status;
        }
        std::cout << std::endl;
    }
}

}  // namespace GameBoard