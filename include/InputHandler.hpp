//
//  InputHandler.hpp
//  SudokuSolverCPP
//
//  Created by OllieLTH on 25/03/2020.
//  Copyright © 2020 OllieLTH. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace SudokuInput
    {
    std::vector<std::vector<int> > read_from_csv(std::string filename);
    }

#endif /* InputHandler_hpp */
