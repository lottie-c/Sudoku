#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main(){ 

  char board[9][9];   
  

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;
  
  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);
  
  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;
  
  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;


  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

 
  
  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8",'1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  //should not be valid, position is outwith board
  cout << "Putting '1' into K8 is ";
  if (!make_move("K8",'1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  //should not be valid 10 is not a digit
  cout << "Putting '10' into I8 is ";
  if (!make_move("I8",'10', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  //should not be valid digit already in column
  cout << "Putting '2' into D1 is ";
  if (!make_move("D1",'2', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

 //should not be valid digit is already in row
  cout << "Putting '5' into B8 is ";
  if (!make_move("B8",'5', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

  //should not be valid digit is already in 3x3 grid
  cout << "Putting '8' into B4 is ";
  if (!make_move("B4",'8', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  
  
  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;

  
  cout << "====================== Question 4 ======================" << endl << endl;
  

    load_board("easy.dat", board);
    if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;


  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
 

  cout << "====================== Question 5 ======================" << endl << endl;

  
  //solve the mystery boards
  load_board("mystery1.dat", board);
  if (solve_board(board)){
    cout << "The 'mystery1' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
 


  load_board("mystery2.dat", board);
  if (solve_board(board)){
    cout << "The 'mystery2' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
 
  
   load_board("mystery3.dat", board);
   if (solve_board(board)){
    cout << "The 'mystery3' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;
  
  return 0;
}

