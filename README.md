# SudokuSolver

A command line application to solve regular sudoku problems (https://en.wikipedia.org/wiki/Sudoku) of any difficulty level.  The application is written in C++ and uses a backtracking algorithm.  It has been tested and works on OSX.


## Downloading and installation

For OSX users

```
// Download from github
~ $ git clone https://github.com/OllieLTH/SudokuSolver

// Go to SudokuSolver directory
~ $ cd SudokuSolver

// Build using make
~/SudokuSolver $ make
```


## Running the solver 

In ```./data/puzzle.csv``` there is already an example sudoku puzzle that shows how the puzzle should be written as a ```.csv``` in order to be compatible with the solver.  It is possible to edit this existing puzzle, or write new ones, in the same format.  Once the program has been downloaded and installed it can be run like so.

```
// Go to SudokuSolver directory
~ $ cd SudokuSolver

// Run the executable
~/SudokuSolver $ bin/solution data/input.csv
```

Please note that ```data/input.csv``` can be changed to the filepath containing any Sudoku puzzle that you wish to solve, given that it is in the correct format.
