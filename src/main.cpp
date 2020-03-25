//
//  main.cpp
//  SudokuSolverCPP
//
//  Created by Ollie Harvey on 24/03/2020.
//  Copyright © 2020 Ollie Harvey. All rights reserved.
//

#include <ctime>
#include <iostream>
#include <string>

#include "BoardSetup.hpp"
#include "InputHandler.hpp"
#include "Solver.hpp"

int main(int argc, char *argv[]) {

    // Retrieve input and set up solver
    std::vector<std::vector<int> > input_board = SudokuInput::read_from_csv(argv[1]);
    SudokuBoard unsolved_board(input_board);
    Solver solved_board(unsolved_board);
    
    // Call, and time, run_solver() to solve the Sudoku
    std::clock_t start_time, end_time;
    start_time = std::clock();
    solved_board.run_solver();
    end_time = std::clock();
    
    // Time taken to run
    std::cout << "Solver took: " << (double) (end_time - start_time) / CLOCKS_PER_SEC << "seconds.\n\n";
    
    // Print out solver results
    solved_board.print_solver_results();
    
    return 0;
}
