//
//  InputHandler.cpp
//  SudokuSolverCPP
//
//  Created by OllieLTH on 25/03/2020.
//  Copyright © 2020 OllieLTH. All rights reserved.
//

#include "InputHandler.hpp"

bool isSingleDigit(std::string str) {
    if (str.size() != 1) {
        return false;
    }
    else if (!isdigit(str[0])) {
        return false;
    }
    else {
        return true;
    }
}


std::vector<std::vector<int> > SudokuInput::read_from_csv(std::string inFilename) {
    
    // Use fstream and stringstream to parse files
    std::ifstream inFile(inFilename);
    
    // Throw error if input file doesn't open
    if (!inFile.is_open())
    {
        std::cout << "Error opening input file" << std::endl;
    }
    
    // Initialize a 2D vector to store the output
    std::vector<std::vector<int> > output;
    
    // Read file line by line (delimiter: '\n')
    std::string input_line;
    while (std::getline(inFile, input_line, '\n')) {
        std::istringstream input_linestream(input_line);
        std::vector<int> input_row;
        std::string value;
        // Split each line into its component data (delimiter: ',')
        while (std::getline(input_linestream, value, ',')) {
            // Ensure each piece of data is an integer in 0-9
            if (isSingleDigit(value)) {
                input_row.push_back(stoi(value));
            }
            else {
                std::cout << "Invalid data type (should be integers in 0-9)" << std::endl;
            }
        }
        output.push_back(input_row);
    }
    
    // Assert input had valid shape (9x9)
    if (output.size() != 9) {
        std::cout << "Invalid number of rows in input (should be 9)" << std::endl;
    }
    for (int i = 0; i < 9; i++) {
        if (output[i].size() != 9 ) {
            std::cout << "Invalid number of columns in input (should be 9)" << std::endl;
        }
    }
    
    // Close the input file
    inFile.close();

    return output;
}
