#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/board/board.h"
#include "../inc/game/game.h"
#include "../inc/game/command_processor.h"

int main() {
  /* struct Board board; */
  
  /* buildBoardArrays(6, 4, &board); */

  
  /* for (int i = 0; i < 4; ++i) { */
  /*   for (int j = 0; j < 6; ++j) { */
  /*     printf("%d ", board.mine_pointer[i][j]); */
  /*   } // for */
  /*   printf("\n"); */
  /* } // for */

  /* printf("\n"); */
  
  /* for (int i = 0; i < 4; ++i) { */
  /*   for (int j = 0; j < 6; ++j) { */
  /*     printf("%d ", board.board_pointer[i][j]); */
  /*   } // for */
  /*   printf("\n"); */
  /* } // for */

  printWelcome();
  printf("\n");
  printWin();
  printf("\n");
  printLoss();
  printf("\n");
  return 0;
} // main
