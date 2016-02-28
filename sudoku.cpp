#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */
 
bool is_complete(char board[9][9]){

  for(int i=0; i < 9; i++){/* i are rows*/
    for(int j=0; j < 9; j++){/*  j are columns*/
      if (!isdigit(board[i][j])){/*for each element in the grid check 
		  if element is a digit, if you reach an element that is not a 
		  * digit function ends and returns false, else it returns 
		  * true.*/
	return false;
      }
    }
  }
  return true;
}


bool make_move(char position[2], char digit, char board[9][9]){
  
  int  row, col;
  row = static_cast<int>(position[0]) - 65;
  col = static_cast<int>(position[1]) - 49;

  if (valid_position(row, col) && valid_digit(digit) 
	&& empty_cell(row, col, board) 
	&& no_copy_in_column(col, digit, board) 
	&& no_copy_in_row(row, digit, board) 
	&& no_copy_in_grid(row, col, digit, board)){

    board[row][col] = digit;
    return true;

  }else
    return false;
  
}


bool save_board(const char *filename, char board[9][9]){

  int i, j;
  ofstream out_stream(filename);
  
  for (i = 0; i < 9; i++){//iterate through the rows
    for (j = 0; j < 9; j++){//iterate through the columns
     
      char character;
      character = board[i][j];
      out_stream.put(character);//out put 'character' to 'filename'
    }
    out_stream.put('\n');//take a new line at the end of each row
  }
  out_stream.close();
  if ((i == 9 ) && (j == 9))
    return true;
  else
    return false;
}

bool solve_board(char board[9][9]){

  int count = 0;

  if (solve_board_count(board, count))
    return true;
  else
    return false;
}
  
//MY HELPER FUNCTIONS

bool valid_position(int row, int col){
  
   if ((row < 0)||(row > 8)){ //check if row position is on the board
    return false;
   }else  if ((col < 0)||(col > 8)){
	   //check if col position is on the board
    return false;
   }else
     return true;
}


bool valid_digit(char digit){

  if ((digit <'1')||(digit > '9')) 
    return false;
  else
    return true;
}


bool empty_cell(int row,int col, char board[9][9]){
 
  if (board[row][col]=='.')
    return true;
  else
    return false;
}


bool no_copy_in_row(int row, char digit, char board[9][9]){

  int  j;
  for (j = 0; j < 9; j++){

    if (board[row][j] == digit)
      return false;
  }
     return true;
}


bool no_copy_in_column(int col, char digit, char board[9][9]){

  int  i;
  for (i = 0; i < 9; i++){

    if (board[i][col] == digit)
      return false;
  }
     return true;
}


bool no_copy_in_grid(int row, int col, char digit, char board[9][9]){

  int i, j;
  /*move current row position to furthest left square of 3x3 grid*/
  if (row % 3 == 1){
    row = row - 1;
  }else if (row % 3 == 2){
    row = row - 2;
  }

  /*move current column position to top of 3x3 grid*/
  if (col % 3 == 1){
    col = col -1;
  }else if (col % 3 == 2){
    col = col - 2;
  }
  /*move through grid checking if 'digit' is already present in grid*/
  for (i = row; i < row + 3 ; i++){
    for (j = col; j < col + 3; j++){
      if (board[i][j] == digit)
	return false;
    }
  }
  return true;
}


bool solve_board_count(char board[9][9], int &count){

  int row = 0, col = 0; 
  char digit;
  char position_array[2];
   

 /*find the next empty square in the grid*/
  while((row < 9)  && (board[row][col] != '.')){
    col++;
    
    if (col == 9){
      row++;
      col = 0;
    }
  }

  position_array[0] = static_cast<char>(row) + 65;
  position_array[1] = static_cast<char>(col) + 49;

 
  if (is_complete(board)){ //base case, if every square is 
	  //occupied by a digit the puzzle is solved
    cout << "The number of times make_move() returns true is: "<< count
     << endl;
    return true;
  }
  
/*try 'digit' at position[row][col], if the move is valid call 
 * solve_board; thus find next empty position and try to place a digit 
 * and so on - if a solution can't be found return changed values to 
 * '.' and go back to try the next digit*/
  for (digit = '1'; digit <= '9'; digit++){
  
    if (make_move(position_array, digit, board)){
      count++; // count the number of times make_move() returns true, 
      //to ascertain difficulty
      if (solve_board_count(board, count)){
       return true;
      }else{
       board[row][col] = '.';
      }
    }
  }
  return false;
}



