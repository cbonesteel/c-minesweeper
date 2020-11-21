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
