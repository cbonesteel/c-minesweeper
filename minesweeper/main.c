#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board/board.h"

int main() {
  struct Board board;
  
  buildBoard(6, 4, &board);

  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 6; ++j) {
      printf("%d ", board.mine_pointer[i][j]);
    } // for
    printf("\n");
  } // for

  for (int i = 0; i < 4; ++i) {
    free(board.mine_pointer[i]);
  } // for

  free(board.mine_pointer);
  
  return 0;
} // main
