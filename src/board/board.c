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
bool buildBoardArrays(int width, int height, struct Board *board) {
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
  board->board_pointer = (int **)malloc(height * sizeof(int*));
  for (int i = 0; i < height; ++i) {
    board->board_pointer[i] = (int *)malloc(width * sizeof(int));
  } // for

  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; j++) {
      board->board_pointer[i][j] = 0;
    } // for
  } // for
  
  return true;
  
} // buildBoard

/**
 * This function takes a board struct and frees all the arrays from memory.
 *
 * @param board the board to be freed
 */
void destructBoard(struct Board *board) {
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
} // destructBoard
