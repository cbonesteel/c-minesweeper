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

  game__build_game(&game);
  
  board__place_mine(1, 1, &game.board);
  board__place_mine(1, 2, &game.board);

  for (int i = 0; i < board__get_y(&game.board); i++) {
    for (int j = 0; j < board__get_x(&game.board); j++) {
      printf("%c ", game.board.board_pointer[i][j]);
    } // for
    printf("\n");
  } // for

  printf("Num Mines: %d", game.board.board_num_mines);
  
  game__take_game_input(&game);

  for (int i = 0; i < board__get_y(&game.board); i++) {
    for (int j = 0; j < board__get_x(&game.board); j++) {
      printf("%c ", game.board.board_pointer[i][j]);
    } // for
    printf("\n");
  } // for

  printf("Num Mines: %d", game.board.board_num_mines);

  return 0;
} // main
