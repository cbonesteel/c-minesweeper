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
  for (int i = 0; i < height; ++i) {
    board->mine_pointer[i] = (bool *)malloc(width * sizeof(bool));
  } // for

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; j++) {
      board->mine_pointer[i][j] = false;
    } // for
  } // for

  // Build array for game board
  board->board_pointer = (char **)malloc(height * sizeof(char*));
  for (int i = 0; i < height; ++i) {
    board->board_pointer[i] = (char *)malloc(width * sizeof(char));
  } // for

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; j++) {
      board->board_pointer[i][j] = '*';
    } // for
  } // for

  // Build array for reveal tracking
  board->reveal_pointer = (bool **)malloc(height * sizeof(bool*));
  for (int i = 0; i < height; ++i) {
    board->reveal_pointer[i] = (bool *)malloc(width * sizeof(bool));
  } // for

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; j++) {
      board->reveal_pointer[i][j] = false;
    } // for
  } // for
  
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
  if (board->reveal_pointer[x][y] == 0) {
    board->reveal_pointer[x][y] = 1;
    
    // TODO: Make this do something to actually reveal
    board->board_pointer[x][y] = 1;
    return true;
  } else {
    return false;
  } // if
} // board__reveal
