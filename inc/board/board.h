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
  int board_x;
  int board_y;
}; // board

// constructor / destructor
bool board__build_array(int width, int height, struct Board *board); // Default Constructor
void board__destruct(struct Board *board); // Deconstructor

// getters/setters
void board__set_x(int x, struct Board *board);
void board__set_y(int y, struct Board *board);
int board__get_x(struct Board *board);
int board__get_y(struct Board *board);

// user command processors
bool board__flag(int x, int y, struct Board *board);
bool board__reveal(int x, int y, struct Board *board);

// mine placer
void board__place_mine(int x, int y, struct Board *board);

// reveal utility
int board__count_num_adjacent(int x, int y, struct Board *board);
bool board__contains_mine(int x, int y, struct Board *board);

#endif // BOARD_H
