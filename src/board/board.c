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

  board__set_x(width, board);
  board__set_y(height, board);

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
 * This function takes an y value and a board and sets the baord's
 * max y value.
 *
 * @param y the y length
 * @param board the board to be configured
 */
void board__set_y(int y, struct Board *board) {
  board->board_y = y;
} // board__set_y

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
  if (board->reveal_pointer[x][y] == 0) {
    board->board_pointer[x][y] = 'F';
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
    board->board_pointer[x][y] = board__count_num_adjacent(x, y, board);
    board->reveal_pointer[x][y] = true;
    
    // TODO: Make Recursive Reveal if Needed
    
    return true;
  } else {
    return false;
  } // if
} // board__reveal

//-----------------//
//   MINE PLACER   //
//-----------------//

/**
 * This function takes an x and y coordinate and places
 * the mine on the mine_pointer array to keep track of the mines.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @board the board for the mine to be placed on
 */
void board__place_mine(int x, int y, struct Board *board) {
  board->mine_pointer[x][y] = true;
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
