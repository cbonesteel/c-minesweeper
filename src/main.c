/**
 * @file main.c
 * @brief The main driver for the program.
 *
 * Source code to run the program. Contains one function, the main
 * function. The main function simply calls the program running loop.
 * 
 * @author Cameron Bonesteel
 * @date Novemeber 8, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/board/board.h"
#include "../inc/game/game.h"
#include "../inc/game/command_processor.h"

int main() {
  struct Game game;

  game__buildGame(&game);

  board__place_mine(1, 1, &game.board);
  board__place_mine(1, 2, &game.board);
  
  printf("%d\n", board__count_num_adjacent(0, 1, &game.board));
  
  return 0;
} // main
