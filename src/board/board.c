/**
 * @file board.c
 * @brief Implementation for the game board functions.
 *
 * Source code for the board. This fundamentaly represents the
 * functions that would be members of the board struct. All
 * functions take in a board to process all actions on.
 *
 * Design Philosophy:
 *
 * A board will initially be built and all three 2D arrays will initialized to
 * false or '*'s, depending on the data type. The "game" can then generate a 
 * board and place mines on the mine_pointer array. The game will take place
 * and be displayed entirely from the board_pointer array. The mine_pointer
 * array is to keep track of the mines without modifying their position on
 * accident. The reveal_pointer array is to keep track of positions that have
 * already beenrevealed by the player to avoid accidental duplicate reveal
 * functions.
 *
 * @author Cameron Bonesteel
 * @date Novemeber 8, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../inc/board/board.h"

//------------------------------//
//   CONSTRUCTOR / DESTRUCTOR   //
//------------------------------//

/**
 * This function takes a specified height and width and builds the passed
 * in board's arrays. This function returns a boolean to specify if the
 * build was successful.
 *
 * @param width the width of the board
 * @param height the height of the board
 * @param board the board struct to be built
 *
 * @return false if height OR width < 2; true otherwise
 */
bool board__build_array(int width, int height, struct Board *board) {
  if (width < 2 || height < 2) {
    return false;
  } // if

  // Build array for mines
  board->mine_pointer = (bool **)malloc(height * sizeof(bool*));
  for (int i = 0; i < height; i++) {
    board->mine_pointer[i] = (bool *)malloc(width * sizeof(bool));
  } // for

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board->mine_pointer[i][j] = false;
    } // for
  } // for

  // Build array for game board
  board->board_pointer = (char **)malloc(height * sizeof(char*));
  for (int i = 0; i < height; i++) {
    board->board_pointer[i] = (char *)malloc(width * sizeof(char));
  } // for

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board->board_pointer[i][j] = '*';
    } // for
  } // for

  // Build array for reveal tracking
  board->reveal_pointer = (bool **)malloc(height * sizeof(bool*));
  for (int i = 0; i < height; i++) {
    board->reveal_pointer[i] = (bool *)malloc(width * sizeof(bool));
  } // for

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      board->reveal_pointer[i][j] = false;
    } // for
  } // for

  board__set_x(height, board);
  board__set_y(width, board);

  board->board_num_mines = 0;
  board->board_num_flags = 0;
  
  return true;
} // board__build_array

/**
 * This function takes a board struct and frees all the arrays from memory.
 *
 * @param board the board to be freed
 */
void board__destruct(struct Board *board) {
  // free mine_pointer
  for (int i = 0; i < 4; ++i) {
    free(board->mine_pointer[i]);
  } // for
  
  free(board->mine_pointer);

  // free board_pointer
  for (int i = 0; i < 4; ++i) {
    free(board->board_pointer[i]);
  } // for
  
  free(board->board_pointer);

  // free reveal_pointer
  for (int i = 0; i < 4; ++i) {
    free(board->reveal_pointer[i]);
  } // for
  
  free(board->reveal_pointer);
} // board__destruct

//-----------------------//
//   GETTERS / SETTERS   //
//-----------------------//

/**
 * This function takes an x value and a board and sets the baord's
 * max x value.
 *
 * @param x the x length
 * @param board the board to be configured
 */
void board__set_x(int x, struct Board *board) {
  board->board_x = x;
} // board__set_x

/**
 * This function takes an y value and a board and sets the board's
 * max y value.
 *
 * @param y the y length
 * @param board the board to be configured
 */
void board__set_y(int y, struct Board *board) {
  board->board_y = y;
} // board__set_y

/**
 * This function takes a bool value anda  board and sets the board's
 * no fog value.
 *
 * @param no_fog the no_fog value
 * @param board the board to be configured
 */
void board__set_no_fog(bool no_fog, struct Board *board) {
  board->board_no_fog = no_fog;
} // board__set_no_fog

/**
 * This function returns the max x value of the passed in board.
 *
 * @param board the board to get the x max of
 * 
 * @return the x max
 */
int board__get_x(struct Board *board) {
  return board->board_x;
} // board__get_x

/**
 * This function returns the max y value of the passed in board.
 *
 * @param board the board to get the y max of
 * 
 * @return the y max
 */
int board__get_y(struct Board *board) {
  return board->board_y;
} // board__get_y

/**
 * This function retuns the no fog value of the board.
 *
 * @param board the board to get the no fog value of
 * 
 * @return the no fog value
 */
bool board__get_no_fog(struct Board *board) {
  return board->board_no_fog;
} // board__get_no_fog

/**
 * This function returns the number of unflagged mines.
 *
 * @param board the board to return the value on
 *
 * @return the number of mines
 */
int board__get_num_mines(struct Board *board) {
  return board->board_num_mines;
} // board__get_num_mines

/**
 * This function returns the number of flagged tiles.
 *
 * @param board the board to return the value on
 *
 * @return the number of flags
 */
int board__get_num_flags(struct Board *board) {
  return board->board_num_flags;
} // board__get_num_flags

//-----------------------------//
//   USER COMMAND PROCESSORS   //
//-----------------------------//

/**
 * This function replaces the specified position with a flag (F).
 * This function returns true if operation can be completed, ie. 
 * the spot has yet to be revealed. Returns false otherwise.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param board the board to be modified
 *
 * @return true if flag is successful; false otherwise
 */
bool board__flag(int x, int y, struct Board *board) {
  if (board->reveal_pointer[x][y] == false) {
    board->board_pointer[x][y] = 'F';
    board->board_num_flags++;
    return true;
  } else {
    return false;
  } // if
} // board__flag

/**
 * This function reveals the specified position. This function
 * will only change the specified square to reveal either a loss
 * or a number of mines adjacent. The function game__reveal will
 * handle recursive reveal operations. Returns true if reveal is
 * successful, ie. the spot has yet to be revealed. Returns false
 * otherwise.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param board the board to be modified
 * 
 * @return true if reveal is succesful; false otherwise
 */
bool board__reveal(int x, int y, struct Board *board) {
  if (board->reveal_pointer[x][y] == false) {
    if (x >= board__get_x(board)) {
      return false;
    } else if (y >= board__get_y(board)) {
      return false;
    } // if

    if (board->board_pointer[x][y] == 'F') {
      board->board_num_flags--;
    } // if
    board->board_pointer[x][y] = board__count_num_adjacent(x, y, board) + '0';
    board->reveal_pointer[x][y] = true;

    if (board__count_num_adjacent(x, y, board) == 0) {
      bool x_left = x - 1 >= 0;
      bool x_right = x + 1 < board__get_x(board);
      bool y_top = y + 1 < board__get_y(board);
      bool y_bottom = y - 1 >= 0;
      // reveal right column
      if (x_right) {
        if (y_top) {
          board__reveal(x + 1, y + 1, board);
        } // if
        if (y_bottom) {
          board__reveal(x + 1, y - 1, board);
        } // if
        board__reveal(x + 1, y, board);
      } // if
      // reveal left column
      if (x_left) {
        if (y_top) {
          board__reveal(x - 1, y + 1, board);
        } // if
        if (y_bottom) {
          board__reveal(x - 1, y - 1, board);
        } // if
        board__reveal(x - 1, y, board);
      } // if
      // reveal tile above
      if (y_top) {
        board__reveal(x, y + 1, board);
      } // if
      // reveal tile below
      if (y_bottom) {
        board__reveal(x, y - 1, board);
      } // if
    } // if
    
    return true;
  } else {
    return false;
  } // if
} // board__reveal

/**
 * This function places a guess marker on the specified position.
 * This function will only do this if the spot has yet to be revealed.
 * Returns true if successful, false otherwise.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param board the board to be modified
 *
 * @return true if successful; false otherwise
 */
bool board__guess(int x, int y, struct Board *board) {
  /* Check if the spot has already been revealed */
  if (board->reveal_pointer[x][y] == true) {
    printf("\nTile already revealed\n"); // TODO: Change when game design is finalized
    return false;
  } else {
    board->board_pointer[x][y] = '?';
    return true;
  } // else
} // board__guess

//-----------------//
//   MINE PLACER   //
//-----------------//

/**
 * This function takes an x and y coordinate and places
 * the mine on the mine_pointer array to keep track of the mines.
 * Returns true if mine was placed, returns false otherwise.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @board the board for the mine to be placed on
 *
 * @return true if mine is placed; false otherwise
 */
bool board__place_mine(int x, int y, struct Board *board) {
  if (board->mine_pointer[x][y] == false) {
    board->mine_pointer[x][y] = true;
    board->board_num_mines++;
    return true;
  } else {
    return false;
  } // if
} // board__place_mine

//--------------------//
//   REVEAL UTILITY   //
//--------------------//

/**
 * This function takes in an x and y and counts the number of mines
 * in the adjacent tiles. Returns this value.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param the board to check
 *
 * @return the number of mines adjacent to this square
 */
int board__count_num_adjacent(int x, int y, struct Board *board) {
  int count = 0;

  bool x_left = (x - 1) >= 0;
  bool x_right = (x + 1) < board__get_x(board);
  bool y_top = (y + 1) < board__get_y(board);
  bool y_bottom = (y - 1) >= 0;
  
  // Left Column
  if (x_left) {
    if (y_top) { // left top
      if (board->mine_pointer[x - 1][y + 1] == true) {
        count++;
      } // if
    } // if
    if (y_bottom) { // left bottom
      if (board->mine_pointer[x - 1][y - 1] == true) {
        count++;
      } // if
    } // if
    // left center
    if (board->mine_pointer[x - 1][y] == true) {
      count++;
    } // if
  } // if

  // Right Column
  if (x_right) {
    if (y_top) { // right top
      if (board->mine_pointer[x + 1][y + 1] == true) {
        count++;
      } // if
    } // if
    if (y_bottom) { // right bottom
      if (board->mine_pointer[x + 1][y - 1] == true) {
        count++;
      } // if
    } // if
    // right center
    if (board->mine_pointer[x + 1][y] == true) {
      count++;
    } // if
  } // if

  // Tile Above
  if (y_top) {
    if (board->mine_pointer[x][y + 1] == true) {
      count++;
    } // if
  } // if

  // Tile Below
  if (y_bottom) {
    if (board->mine_pointer[x][y - 1] == true) {
      count++;
    } // if
  } // if

  return count;
} // board__count_num_adjacent

/**
 * This function takes an x, a y, and a board struct and returns true
 * if the specified position contains a mine. Returns false otherwise.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param board the board to be checked
 *
 * @return true if the spot contains a mine; false otherwise
 */
bool board__contains_mine(int x, int y, struct Board *board) {
  if (board->mine_pointer[x][y] == true) {
    return true;
  } else {
    return false;
  } // if
} // board__contains_mine

//---------------------//
//   PRINT FUNCTIONS   //
//---------------------//

/**
 * This function takes in a board and prints the board to the screen.
 *
 * @param board the board to be printed
 */
void board__print_board(struct Board *board) {
  for (int i = board__get_x(board) - 1; i >= 0; i--) {
    if (i >= 10) {
      printf("%d ", i);
    } else {
      printf(" %d ", i);
    } // if
    for (int j = 0; j < board__get_y(board); j++) {
      if (board__get_y(board) > 10) {
        printf("[ %c ]", board->board_pointer[i][j]);
      } else {
        printf("[%c]", board->board_pointer[i][j]);
      } // if
    } // for
    printf("\n");
  } // for

  if (board__get_y(board) > 10) {
    printf("     "); 
  } else {
    printf("    "); 
  } // if
  
  for (int i = 0; i < board__get_y(board); i++) {
    if (board__get_y(board) > 10) {
      if (i < 10) {
        printf("%d    ", i);
      } else {
        printf("%d   ", i);
      } // if
    } else {
      printf("%d  ", i);
    } // if
  } // for
} // board__print_board

/**
 * This function takes in a board and prints the board to the screen
 * with mines visable to the user.
 *
 * @param board the board to print
 */
void board__print_no_fog(struct Board *board) {
  for (int i = board__get_x(board) - 1; i >= 0; i--) {
    if (i >= 10) {
      printf("%d ", i);
    } else {
      printf(" %d ", i);
    } // if
    for (int j = 0; j < board__get_y(board); j++) {
      if (board__get_y(board) > 10) {
        if (board->mine_pointer[i][j] == true) {
          printf("[ @ ]");
        } else {
          printf("[ %c ]", board->board_pointer[i][j]);
        } // if
      } else {
        if (board->mine_pointer[i][j] == true) {
          printf("[@]");
        } else {
          printf("[%c]", board->board_pointer[i][j]);
        } // if
      } // if
    } // for
    printf("\n");
  } // for

  if (board__get_y(board) > 10) {
    printf("     "); 
  } else {
    printf("    "); 
  } // if
  
  for (int i = 0; i < board__get_y(board); i++) {
    if (board__get_y(board) > 10) {
      if (i < 10) {
        printf("%d    ", i);
      } else {
        printf("%d   ", i);
      } // if
    } else {
      printf("%d  ", i);
    } // if
  } // for
} // board__print_no_fog
