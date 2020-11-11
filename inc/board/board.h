/**
 * @file board.h
 * @brief The header for board.
 */
#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Board {
  bool **mine_pointer;
  bool **reveal_pointer;
  char **board_pointer;
}; // board

bool board__build_array(int width, int height, struct Board *board); // Default Constructor
void board__destruct(struct Board *board); // Deconstructor

// command helpers
bool board__flag(int x, int y, struct Board *board);
bool board__reveal(int x, int y, struct Board *board);

#endif // BOARD_H
