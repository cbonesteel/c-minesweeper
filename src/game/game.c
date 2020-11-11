/**
 * @file game.c
 * @brief Implementation for the game functions.
 *
 * Source code for the game. This contains all the functions
 * needed to run the game, expect command processes.
 *
 * Design Philosophy:
 *
 * This file contains the functions needed to run the game. This includes
 * the game loop, print statements, and tunnels to the command processors.
 *
 * @author Cameron Bonesteel
 * @date Novemeber 10, 2020
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
void game__printWelcome() {
  FILE *fp;
  fp = fopen("resources/game/welcome.txt", "r");
  char buff[255];

  for (int i = 0; i < 6; ++i) {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff );
  } // for
    
  fclose(fp);
} // game__printWelcome

/**
 * This function prints the win screen for the game.
 */
void game__printWin() {
  FILE *fp;
  fp = fopen("resources/game/win.txt", "r");
  char buff[255];

  for (int i = 0; i < 9; ++i) {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff );
  } // for
    
  fclose(fp);
} // game__printWin

/**
 * This function prints the loss screen for the game.
 */
void game__printLoss() {
  FILE *fp;
  fp = fopen("resources/game/loss.txt", "r");
  char buff[255];

  for (int i = 0; i < 5; ++i) {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff );
  } // for
    
  fclose(fp);
} // game__printLoss

/**
 * This function builds a specified game. This function builds
 * the board to the specified size and difficulty. The won and noFog
 * params are set to false by default.
 * 
 * @param game the game to have it's board built
 */
void game__buildGame(struct Game *game) {
  // TODO: Take input for board size
  game->noFog = false;
  game->won = false;
  board__build_array(10, 10, &game->board);
  // TODO: Place mines based on settings
} // game__buildBoard

/**
 * This function prompts the user for game input. This function
 * then passes necessary information to the command processor to
 * be handled.
 */
void game__takeGameInput() {
  // TODO: Implementation
} // game__takeGameInput
