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
   
  /* board__flag(2, 5, &board); */
  /* board__reveal(3, 5, &board); */

  command_processor__help();
  
  printf("MINES\n");
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%d ", game.board.mine_pointer[i][j]);
    } // for
    printf("\n");
  } // for

  printf("\nBOARD\n");
  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%c ", game.board.board_pointer[i][j]);
    } // for
    printf("\n");
  } // for

  printf("\nREVEAL\n");
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%d ", game.board.reveal_pointer[i][j]);
    } // for
    printf("\n");
  } // for
  
  /* printWelcome(); */
  /* printf("\n"); */
  /* printWin(); */
  /* printf("\n"); */
  /* printLoss(); */
  /* printf("\n"); */

  return 0;
} // main
