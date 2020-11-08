#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"

/*
 */
bool buildBoard(int width, int height, struct Board *board) {
  board->mine_pointer = (int **)malloc(height * sizeof(int*));
  for (int i = 0; i < height; ++i) {
    board->mine_pointer[i] = (int *)malloc(width * sizeof(int));
  } // for

  int count = 0;
  
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; j++) {
      board->mine_pointer[i][j] = ++count;
    } // for
  } // for
  
  return true;
  
} // buildBoard
