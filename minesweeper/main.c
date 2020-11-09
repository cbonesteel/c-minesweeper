#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board/board.h"

int main() {
  struct Board board;
  
  buildBoardArrays(6, 4, &board);

  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%d ", board.mine_pointer[i][j]);
    } // for
    printf("\n");
  } // for

  printf("\n");
  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%d ", board.board_pointer[i][j]);
    } // for
    printf("\n");
  } // for
  
  
  return 0;
} // main
