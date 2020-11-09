#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Board {
  bool **mine_pointer;
  int **board_pointer;
}; // board

bool buildBoardArrays(int width, int height, struct Board *board); // Default Constructor
void destructBoard(struct Board *board); // Deconstructor

#endif // BOARD_H
