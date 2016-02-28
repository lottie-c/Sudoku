#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);

//required functions

/*FUNCTION TO CHECK IF ALL POSITIONS IN THE 9X9 SUDOKU BOARD 'board' ARE OCCUPIED BY DIGITS*/
bool is_complete(char board[9][9]);

/*FUNCTION WHICH ATTEMPTS TO PLACE THE CHARACTER 'digit' ON THE SUDOKU BOARD 'board' IN PLACE 'position'. IF THE MOVE IS VALID WITHIN THE RULES OF SUDOKU AND POSITION IS WITHIN THE 9X9 SQUARE DIGIT IS PLACED AND FUNCTION RETURNS TRUE'.*/
bool make_move(char position[2], char digit, char board[9][9]);

/*FUNCTION OUTPUTS THE CHARACTER ARRAY 'board' TO A FILE NAMED 'filename', IF THIS IS ACHIEVED FUNCTION RETURNS TRUE, OTHERWISE IT RETURNS FALSE*/
bool solve_board(char board[9][9]);

/*FUNCTION TO SOLVE THE SUDOKU BOARD 'board' USING RECURSION*/
bool save_board(const char *filename, char board[9][9]);

//helper functions

/*FUNCTION RETURNS TRUE IF 'POSITION' DOES NOT EXCEED ROW/COLUMN PARAMETERS AND FALSE OTHERWISE*/
bool valid_position(int row, int col);


/*FUNCTION RETURNS TRUE IF  DIGIT IS BETWEEN 1 AND 9 INCLUSIVE AND FALSE OTHERWISE*/
bool valid_digit(char digit);

/*FUNCTION RETURNS TRUE IF CELL " board[row][col]" IS EMPTY*/
bool empty_cell(int row, int col, char board[9][9]);

/*FUNCTION RETURNS TRUE IF 'digit' IS NOT ALREADY PRESENT IN ROW 'row' AND FALSE OTHERWISE*/
bool no_copy_in_row(int row, char digit, char board[9][9]);

/*FUNCTION RETURNS TRUE IF 'digit' IS NOT ALREADY PRESENT IN COLUMN 'col', AND FALSE OTHERWISE*/
bool no_copy_in_column(int col, char digit, char board[9][9]);

/*FUNCTION RETURNS TRUE IF 'digit' IS NOT ALREADY PRESENT IN ITS 3X3 GRID AND FALSE OTHERWISE*/
bool no_copy_in_grid(int row, int col, char digit, char board[9][9]);


/*FUNCTION TO SOLVE THE SUDOKU BOARD 'board' USING RECURSION AND COUNT HOW MANY TIMES make_move() RETURNS TRUE*/
bool solve_board_count(char board[9][9], int &count);

#endif

