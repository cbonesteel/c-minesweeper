/**
 * @file menu.c
 * @brief Implementation for the menu functions.
 *
 * Source code for the menu functions. This contains all the functions
 * needed to manage the menu, except command processes.
 *
 * Design Philosophy:
 *
 * This file contains the functions needed to manage the menu. This includes
 * print functions and tunnels to the command processors.
 *
 * @author Cameron Bonesteel
 * @date November 21, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/board/board.h"
#include "../../inc/game/game.h"
#include "../../inc/game/command_processor.h"

/**
 * In current implementation with simple yes/no menu, this
 * function only takes yes or no AND process the game to be run.
 * Returns true if it runs, false otherwise;
 *
 * @return true if yes; false otherwise 
 */
bool menu__take_input() {
  struct Game game;
  char input[4];

  printf("\nStart New Game? Y/N: ");
  
  fgets(input, 4, stdin);
    
  if (strncmp(input, "N", 1) == 0 || strncmp(input, "n", 1) == 0 ||
      strncmp(input, "No", 2) == 0 || strncmp(input, "no", 2) == 0) {
    return false;
  } else {
    game__build_game(&game);
    game__play(&game);
    return true;
  } // if
  
} // menu__take_input

/**
 * This function prints the welcome screen for the game.
 */
void menu__print_welcome() {
  FILE *fp;
  fp = fopen("resources/game/welcome.txt", "r");
  char buff[255];

  for (int i = 0; i < 6; ++i) {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff );
  } // for
  
  fclose(fp);
} // game__print_welcome
