#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Board {
  int **mine_pointer;
  // int **board_pointer;
}; // board

bool buildBoard(int width, int height, struct Board *board);
  
#endif // BOARD_H
