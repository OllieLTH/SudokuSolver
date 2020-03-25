//
//  Solver.hpp
//  SudokuSolverCPP
//
//  Created by OllieLTH on 24/03/2020.
//  Copyright © 2020 OllieLTH. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp

#include "BoardSetup.hpp"
#include <vector>

class Solver
{
public:
    // Constructors
    Solver(SudokuBoard unsolved_board);
    
    // Functions for checking validity of a possible entry
    bool is_row_valid(int row, int num);
    bool is_col_valid(int col, int num);
    bool is_box_valid(int col, int row, int num);
    bool is_valid(int col, int row, int num);
    
    // Functions for solving and printing solver results
    void run_solver();
    void print_solver_results();
    
    // Get and set functions
    std::vector<SudokuBoard> get_solutions();
    SudokuBoard get_board();
    int get_n_solutions();
    int get_board_element(int row, int col);
    void set_board_element(int row, int col, int num);
    
private:
    bool isSolverRun;
    int n_solutions;
    std::vector<SudokuBoard> solutions;
    SudokuBoard unsolved_board;
};

#endif /* Solver_hpp */
