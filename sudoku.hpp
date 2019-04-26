//This file contains other file headers and the class definition of Sudoku

#ifndef SUDOKU_SUDOKU_H
#define SUDOKU_SUDOKU_H

#include <iostream>
#include <random>

using namespace std;

class Sudoku {                                      //Declare class sudoku

    int grid[9][9];                               //Create a 9 by 9 grid

    public:                                             //Public functions
    Sudoku(int n);                                      //Sudoku contructor
    int solve();                                        //Function declarations
    void printGrid();
    bool checkValidity(int row, int col, int num);


};



#endif //SUDOKU_SUDOKU_H
