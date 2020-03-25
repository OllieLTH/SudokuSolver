//
//  BoardSetup.cpp
//  SudokuSolverCPP
//
//  Created by Ollie Harvey on 24/03/2020.
//  Copyright © 2020 Ollie Harvey. All rights reserved.
//

#include "BoardSetup.hpp"


// Constructors
SudokuBoard::SudokuBoard() {
    std::vector<std::vector<int> > tmp_board (9, std::vector<int> (9, 0) );
    board = tmp_board;
}

SudokuBoard::SudokuBoard(std::vector<std::vector<int> > vectorised_board) {
    board = vectorised_board;
}


// Function to aesthetically print the board
void SudokuBoard::print_board() {
    std::cout << "\n";
    std::cout << "\t+-------+-------+-------+" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cout << "\t";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                std::cout << "| ";
            }
            std::cout << board[i][j] << " ";
       }
        std::cout << "|" << std::endl;
        if (i % 3 == 2) {
            std::cout << "\t+-------+-------+-------+" << std::endl;
        }
    }
    std::cout << "\n";
}


// Get and set functions
std::vector<std::vector<int> > SudokuBoard::get_board() {
    return board;
}

int SudokuBoard::get_element(int row, int col) {
    return board[row][col];
}

void SudokuBoard::set_element(int row, int col, int num) {
    board[row][col] = num;
}
