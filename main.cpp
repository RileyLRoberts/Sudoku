#include "sudoku.hpp"

/*******************************************************************************************
 * Function Title: Main
 *
 * Summary: Asks for user input for a number of squares to prepopulate, and creates a sudoku
 * board with that many squares prepopulated. If the board is solvable, it solves it.
 *
 * Inputs: A number of prepopulated squares to use
 * Outputs: The generated sudoku board, and if it is solvable, the solved sudoku board.
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Declare a variable to store the user input
 *  Print an introduction to the console
 *  Ask the user for a number of squares to prepopulate
 *  Store the users response
 *  Create an object userSudoku of class Sudoku with the correct number of prepopulated squares
 *  Print the sudoku
 *  Start a new line
 *  If the solve function is a success
 *  Then
 *      Print a success message
 *      Print the solved sudoku
 *  Else
 *      Print a failure message
 *  EndIf
 * End
 * *****************************************************************************************/

int main()                                                                          //Begin
{
    int n;                                                                              //Declare a variable to store the user input
    cout << "Welcome to the Sudoku Puzzle Solver" << endl;                              //Print an introduction to the console
    cout << "Enter number of squares to prepopulate: ";                                 //Ask the user for a number of squares to prepopulate
    cin >> n;                                                                           //Store the users response
    Sudoku userSudoku(n);                                                               //Create an object userSudoku of class Sudoku with the correct number of prepopulated squares
    userSudoku.printGrid();                                                             //Print the sudoku
    cout << endl;                                                                       //Start a new line
    if (userSudoku.solve() == 1) {                                                      //If the solve function is a success
                                                                                        //Then
        cout << "Solved, solution below:" << endl;                                          //Print a success message
        userSudoku.printGrid();                                                             //Print the solved sudoku
    }
    else {                                                                              //Else
        cout << "Sorry, unsolvable. Try again with less prepopulated squares" << endl;      //Print a failure message
    }                                                                                   //EndIf
    return 0;
}                                                                                   //End