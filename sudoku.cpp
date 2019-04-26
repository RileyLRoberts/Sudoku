#include "sudoku.hpp"

/*******************************************************************************************
 * Function Title: Check Validity
 *
 * Summary: Checks to see if a number in a location satisfies the rules of sudoku
 *
 * Inputs: The row and column of the sudoku board, and the number to try
 * Outputs: True or false, true if the number satisfies the rules, false if not
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Loop starting at i=0 and going while i is less than 9, increment by 1
 *      If the value in the inputted row and the the ith column equals the inputted number
 *      Then
 *          Return false
 *      EndIf
 *      If the value in the inputted column and the the ith row equals the inputted number
 *      Then
 *          Return false
 *      EndIf
 *  EndLoop when i is 9
 *  Loop from r=0 while r is less than 3, incrementing by 1
 *      Loop from c=0 while c is less than 3, incrementing by 1
 *          If any value in the 3x3 grid of the inputted location contains the number
 *          Then
 *              Return false
 *          EndIf
 *      EndLoop when r is 3
 *  EndLoop when c is 3
 *  Return true
 * End
 * ******************************************************************************************/

bool Sudoku::checkValidity(int row, int col, int num) {                         //Begin

    for (int i = 0; i<9; i++) {                                                     //Loop starting at i=0 and going while i is less than 9, increment by 1

        if (grid[row][i] == num) {                                                      //If the value in the inputted row and the the ith column equals the inputted number
                                                                                        //Then
            return false;                                                                   //Return false
        }                                                                               //EndIf

        if (grid[i][col] == num) {                                                      //If the value in the inputted column and the the ith row equals the inputted number
                                                                                        //Then
            return false;                                                                   //Return false
        }                                                                               //EndIf

    }                                                                               //EndLoop when i is 9

    for (int r = 0; r < 3; r++) {                                                   //Loop from r=0 while r is less than 3, incrementing by 1
        for (int c = 0; c < 3; c++) {                                                   //Loop from c=0 while c is less than 3, incrementing by 1
            if (grid[(row - (row % 3)) + r][(col - (col % 3)) + c] == num) {                //If any value in the 3x3 grid of the inputted location contains the number
                                                                                            //Then
                return false;                                                                   //Return False
            }                                                                               //EndIf
        }                                                                               //EndLoop when r is 3
    }                                                                               //EndLoop when c is 3

    return true;                                                                    //Return True

}                                                                               //End

/*******************************************************************************************
 * Function Title: Sudoku Constructor
 *
 * Summary: Creates an object of class sudoku with an inputted number of prepopulated squares
 *
 * Inputs: A number of prepopulated squares to use
 * Outputs: An object of class sudoku is created
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Loop for each row
 *      Loop for each column
 *          Set each position to 0
 *      EndLoop when each column is filled
 *  EndLoop when each row is filled
 *  Fill the grid with zeros
 *  Create a seed for the random number generator
 *  Create the random number generator
 *  Create a distribution of numbers to limit the random number generator
 *  Declare variables
 *  Set d to 0
 *  Loop while n is not 0
 *      Set a to a random number between 0 and 8
 *      Set b to a random number between 0 and 8
 *      Set c to a random number between 1 and 9
 *      If the randomly selcted spot is not filled, and putting the random number there satisfies the rules
 *      Then
 *          Place the number in that location
 *      EndIf
 *      Else
 *          Add one to d
 *          If d is greater than 3000
 *          Then
 *              Print an error message stating that a vailid board could not be created, prompt the user to try again
 *              Exit the program
 *          EndIf
 *          Start loop over
 *      EndIf
 *      Subtract one from n
 *  End loop when n is 0
 * End
 * ******************************************************************************************/

Sudoku::Sudoku(int n) {                                                                                         //Begin
    for (int r =0; r<9; r++) {                                                                                      //Loop for each row
        for (int c = 0; c < 9; c++) {                                                                                   //Loop for each column
            grid[r][c] = 0;                                                                                                 //Set each position to 0
        }                                                                                                               //EndLoop when each column is filled
    }                                                                                                               //EndLoop when each row is filled
    unsigned seed = (unsigned) chrono::system_clock::now().time_since_epoch().count();                              //Create a seed for the random number generator
    default_random_engine generator(seed);                                                                          //Create the random number generator
    uniform_int_distribution<int> distribution(1,9);                                                                //Create a distribution of numbers to limit the random number generator
    int a,b,c,d;                                                                                                    //Declare variables
    d=0;                                                                                                            //Set d to 0
    while (n != 0){                                                                                                 //Loop while n is not 0

        a = distribution(generator) - 1;                                                                                //Set a to a random number between 0 and 8
        b = distribution(generator) - 1;                                                                                //Set b to a random number between 0 and 8
        c = distribution(generator);                                                                                    //Set c to a random number between 1 and 9

        if (grid[a][b] == 0 && checkValidity(a,b,c)) {                                                                  //If the randomly selcted spot is not filled, and putting the random number there satisfies the rules
                                                                                                                        //Then
            grid[a][b] = c;                                                                                                 //Place the number in that location

        }                                                                                                               //EndIF
        else {                                                                                                          //Else
            d++;                                                                                                            //Add one to d

            if (d > 3000) {                                                                                                 //If d is greater than 3000
                                                                                                                            //Then
                cout << "Error: No valid board could be generated, try again with less prepopulated squares."<< endl;           //Print an error message stating that a vailid board could not be created, prompt the user to try again
                exit(1);                                                                                                        //Exit the program
            }                                                                                                               //EndIf

            continue;                                                                                                       //Start loop over

        }                                                                                                               //EndIf
        n--;                                                                                                            //Subtract one from n
    }                                                                                                               //End loop when n is 0

}                                                                                                               //End

/*******************************************************************************************
 * Function Title: Solve
 *
 * Summary: Solves a sudoku
 *
 * Inputs: The sudoku grid of the object the function is being performed on
 * Outputs: 1 or 0 for if the sudoku was solved succesfully or not. The sudoku grid of the
 * object being acted on will be filled with the correct solution
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Create a reference array
 *  Loop for each row of the array
 *      Loop for each column of the array
 *          Copy the elements of the grid into the reference array
 *      EndLoop
 *  EndLoop
 *  Declare the number to be place n and start it at one
 *  Declare the starting row as 0
 *  Declare the starting column as 0
 *  Loop while the position in the reference array does not contain 0
 *      Move the column one to the right
 *      If the column goes off the right side of the grid
 *      Then
 *          Move the row down one
 *          Set the column back to 0
 *      EndIf
 *  EndLoop when the position in the reference array contains 0
 *  Loop
 *      If the position can be filled by n legally
 *      Then
 *          Fill the position with n
 *          Set n back to 1
 *          Move the column one to the right
 *          If the column goes off the right side of the grid
 *          Then
 *              Move the row down one
 *              Set the column back to 0
 *          EndIf
 *          If the row goes off the bottom
 *          Then
 *              Return 1 for success
 *          EndIf
 *          Loop while the position in the reference array does not contain 0
 *              Move the column one to the right
 *              If the column goes off the right side of the grid
 *              Then
 *                  Move the row down one
 *                  Set the column back to 0
 *              EndIf
 *              If the row goes off the bottom
 *              Then
 *                  Return 1 for success
 *              EndIf
 *          EndLoop when the position in the reference array contains 0
 *      Else
 *          Add one to n
 *          A label for the goto statement used in succesive backtracking
 *          If n equals 10
 *          Then
 *              Set the value in that position to 0
 *              Move the column 1 to the left
 *              If the column goes off the left side of the grid
 *              Then
 *                  Move the row up one
 *                  Set the column back to 8
 *              EndIf
 *              If the row goes off the top
 *              Then
 *                  Return 0 for failure
 *              EndIf
 *              Loop while the position in the reference array does not contain 0
 *                  Move the column one to the left
 *                  If the column goes off the left side of the grid
 *                  Then
 *                      Move the row up one
 *                      Set the column back to 8
 *                  EndIf
 *                  If the row goes off the top
 *                  Then
 *                      Return 0 for failure
 *                  EndIf
 *              EndLoop
 *              Set n equal to the value in that position plus one
 *              If n equals 10
 *              Then
 *                  Go to the backtrack label in the code
 *              EndIf
 *          EndIf
 *      EndIf
 *  EndLoop
 * End
 * ******************************************************************************************/

int Sudoku::solve() {                               //Begin

    int filled[9][9];                                   //Create a reference array

    for (int r = 0; r<9; r++) {                         //Loop for each row of the array

        for (int c = 0; c<9; c++) {                         //Loop for each column of the array

            filled[r][c] = grid[r][c];                          //Copy the elements of the grid into the reference array

        }                                                   //EndLoop
    }                                                   //EndLoop

    int n = 1;                                          //Declare the number to be place n and start it at one
    int row = 0;                                        //Declare the starting row as 0
    int col = 0;                                        //Declare the starting column as 0

    while (filled[row][col] != 0) {                     //Loop while the position in the reference array does not contain 0
        col++;                                              //Move the column one to the right
        if (col == 9) {                                     //If the column goes off the right side of the grid
                                                            //Then
            row++;                                              //Move the row down one
            col = 0;                                            //Set the column back to zero

        }                                                   //EndIf
    }                                                   //EndLoop

    for(;;) {                                           //Loop


        if (checkValidity(row, col, n)) {                   //If the position can be filled by n legally
                                                            //Then
            grid[row][col] = n;                                 //Fill the position with n
            n = 1;                                              //Set n back to 1

            col++;                                              //Move the column one to the right

            if (col == 9) {                                     //If the column goes off the right side of the grid
                                                                //Then
                row++;                                              //Move the row down one
                col = 0;                                            //Set the column back to 0

            }                                                   //EndIf

            if (row == 9) {                                     //If the row goes off the bottom
                                                                //Then
                return 1;                                           //Return 1 for success
            }                                                   //EndIf

            while (filled[row][col] != 0) {                     //Loop while the position in the reference array does not contain 0

                col++;                                              //Move the column one to the right
                if (col == 9) {                                     //If the column goes off the right side of the grid
                                                                    //Then
                    row++;                                              //Move the row down one
                    col = 0;                                            //Set the column back to zero

                }                                                   //EndIf
                if (row == 9) {                                     //If the row goes off the bottom
                                                                    //Then
                    return 1;                                           //Return 1 for success
                }                                                   //EndIf

            }                                                   //EndLoop when the position in the reference array contains zero

        }
        else {                                              //Else

            n++;                                                // Add one to n

            backtrack_again_label:                              //A label for the goto statement used in succesive backtracking

            if (n == 10) {                                      //If n equals 10
                                                                //Then
                grid[row][col] = 0;                                 //Set the value in that position to 0
                col--;                                              //Move the column 1 to the left

                if (col == -1) {                                    //If the column goes off the left side of the grid
                                                                    //Then
                    row--;                                              //Move the row up one
                    col = 8;                                            //Set the column back to 8

                }                                                   //EndIf

                if (row == -1) {                                    //If the row goes off the top of the grid
                                                                    //Then
                    return 0;                                           //Return 0 for failure
                }                                                   //EndIf

                while (filled[row][col] != 0) {                     //Loop while the position in the refrence array does not contain 0
                    col--;                                              //Move the column one to the left
                    if (col == -1) {                                    //If the column goes off the left side of the grid
                                                                        //Then
                        row--;                                              //Move the row up one
                        col = 8;                                            //Set the column back to 8

                    }                                                   //EndIf
                    if (row == -1) {                                    //If the row goes off the top of the grid
                                                                        //Then
                        return 0;                                           //Return 0 for failure
                    }                                                   //EndIf

                }                                                   //EndLoop when the position in the reference node contains 0

                n = grid[row][col] + 1;                             //Set n equal to the value in that position plus one

                if (n == 10) {                                      //If n equals 10
                                                                    //Then
                    goto backtrack_again_label;                         //Go to the backtrack label in the code
                }                                                   //EndIf

            }                                                   //EndIf

        }                                                   //EndIf

    }                                                   //EndLoop

}                                                   //End

/*******************************************************************************************
 * Function Title: Print grid
 *
 * Summary: Prints the grid stored in the sudoku object it is called upon, using a * in the place of 0s
 *
 * Inputs: The grid of the object it is called on
 * Outputs: The grid printed to the console
 *
 ********************************************************************************************
 * Pseudocode
 *
 * Begin
 *  Loop for each row
 *      Loop for each column
 *          If the value at the location is 0
 *          Then
 *              Print a * to the console
 *          Else
 *              Print the value of the location
 *          EndIF
 *          If the column is the last column
 *          Then
 *              Print a new line
 *          Else
 *              Print a tab
 *          EndIf
 *      EndLoop after each column has been used
 *  EndLoop after each row has been used
 * End
 *
 * ******************************************************************************************/

void Sudoku::printGrid() {              //Begin

    for (int r =0; r<9; r++) {              //Loop for each row

        for (int c = 0; c < 9; c++) {           //Loop for each column


            if (grid[r][c] == 0) {                  //If the value at the location is 0
                                                    //Then
                cout << "*";                            //Print a * to the console

            }
            else {                                  //Else
                cout << grid[r][c];                     //Print the value of the location
            }                                       //EndIf

            if (c == 8) {                           //If the column is the last column
                                                    //Then
                cout << endl;                           //Print a new line
            }
            else {                                  //Else
                cout << "\t";                           //Print a tab
            }                                       //EndIf

        }                                       //EndLoop after each column has been used

    }                                       //EndLoop after each row has been used

}                                       //End


