//
//  Solver.cpp
//  SudokuSolverCPP
//
//  Created by OllieLTH on 24/03/2020.
//  Copyright © 2020 OllieLTH. All rights reserved.
//

#include "Solver.hpp"


// Constructor
Solver::Solver(SudokuBoard unsolved_board) :
n_solutions(0),
isSolverRun(false),
unsolved_board(unsolved_board),
solutions() {}


// Functions for checking validity of a possible entry
bool Solver::is_row_valid(int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (get_board_element(row, i) == num) {
            return false;
        }
    }
    return true;
}

bool Solver::is_col_valid(int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (get_board_element(i, col) == num) {
            return false;
        }
    }
    return true;
}

bool Solver::is_box_valid(int col, int row, int num) {
    int col_ul = col - col % 3;
    int row_ul = row - row % 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (get_board_element(row_ul + i, col_ul + j) == num) {
                return false;
            }
        }
    }
    return true;
}

bool Solver::is_valid(int col, int row, int num) {
    return is_row_valid(row, num) and is_col_valid(col, num) and is_box_valid(col, row, num);
}


// Functions for solving and printing solver results
void Solver::run_solver() {
    isSolverRun = true;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (get_board_element(row, col) == 0) {
                for (int num = 1; num < 10; num++) {
                    if (is_valid(col, row, num)) {
                        set_board_element(row, col, num);
                        run_solver();
                        set_board_element(row, col, 0);
                    }
                }
                return;
            }
        }
    }
    solutions.push_back(get_board());
    n_solutions++;
}

void Solver::print_solver_results() {
    // Check if solver has been run
    if(!isSolverRun) {
        std::cout << "Solver needs to be run with run_solver() before results can be printed." << std::endl;
        return;
    }
    
    // Check the number of solutions
    int n_solutions = get_n_solutions();
    
    // If there are no solutions
    if (n_solutions == 0) {
        std::cout << "There are no solutions to this puzzle." << std::endl;
    }
    
    // If there is one solution
    else if (n_solutions == 1) {
        std::cout << "There is one unique solution to this puzzle: " << std::endl;
        get_solutions()[0].print_board();
    }
    
    // If there are multiple solutions
    else {
        // Print one solution
        std::cout << "There are " << n_solutions << " solutions to this puzzle." << std::endl;
        std::cout << "\nSolution 1: " << std::endl;
        get_solutions()[0].print_board();
        
        // Ask user if they want all solutions printing
        std::cout << "[Y] to see all solutions. " ;
        char tmp;
        std::cin >> tmp;
        if (tmp == 'Y') {
            for (int i = 1; i < n_solutions; i++) {
                std::cout << "Solution " << (i+1) << ": " << std::endl;
                get_solutions()[i].print_board();
            }
        }
    }
}


// Get and set functions
std::vector<SudokuBoard> Solver::get_solutions() {
    return solutions;
}

SudokuBoard Solver::get_board() {
    return unsolved_board;
}

int Solver::get_n_solutions() {
    return n_solutions;
}

int Solver::get_board_element(int row, int col) {
    return unsolved_board.get_element(row, col);
}

void Solver::set_board_element(int row, int col, int num) {
    unsolved_board.set_element(row, col, num);
}
