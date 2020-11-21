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
#include "../inc/menu/menu.h"

int main() {
  struct Game game;
  char input[4];
    
  // TODO: Move Much of this to helper methods
  // main should contain one call to a run function
  menu__print_welcome();
  
  printf("\nStart New Game? Y/N: ");
  
  fgets(input, 4, stdin);
    
  if (strncmp(input, "N", 1) == 0 || strncmp(input, "n", 1) == 0 ||
      strncmp(input, "No", 2) == 0 || strncmp(input, "no", 2) == 0) {
    return 0;
  } else {
    game__build_game(&game);
    game__play(&game);
  } // if
  
  return 0;
} // main
