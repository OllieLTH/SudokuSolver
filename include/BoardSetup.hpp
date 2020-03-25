//
//  BoardSetup.hpp
//  SudokuSolverCPP
//
//  Created by OllieLTH on 24/03/2020.
//  Copyright © 2020 OllieLTH. All rights reserved.
//

#ifndef BoardSetup_hpp
#define BoardSetup_hpp

#include <iostream>
#include <vector>


class SudokuBoard
{
public:
    // Constructors
    SudokuBoard();
    SudokuBoard(std::vector<std::vector<int> > vectorised_board);
    
    // Function to aesthetically print the board
    void print_board();
    
    // Get and set functions
    std::vector<std::vector<int> > get_board();
    int get_element(int row, int col);
    void set_element(int row, int col, int num);
    
private:
    std::vector<std::vector<int> > board;
};


#endif /* BoardSetup_hpp */
