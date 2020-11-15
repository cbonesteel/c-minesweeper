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
 * be handled. Prints out invalid command information if command
 * is invalid.
 *
 * @param game the game to process input on
 */
void game__takeGameInput(struct Game *game) {
  //---VARIABLES---//
  char rawInput[20];

  char * input;
  char * xChar;
  char * yChar;
  
  int x;
  int y;

  // Take in command
  printf("Enter a command: ");
  fgets(rawInput, 20, stdin);

  // Parse command
  input = strtok(rawInput, " ");
  xChar = strtok(NULL, " ");
  yChar = strtok(NULL, " ");

  // Checks if input requiring coordinates is in form [input] [x] [y]
  if ((xChar == NULL || yChar == NULL) &&
      (strncmp(input, "r", 1) == 0 || strncmp(input, "f", 1) == 0)) {
    // Makes input invalid
    input = "x";
  } else if (strncmp(input, "r", 1) == 0 || strncmp(input, "f", 1) == 0) {
    // Sets x and y
    x = atoi(xChar);
    y = atoi(yChar);
  } // if

  // Processes Input by calling correct functions
  if (strncmp(input, "r", 1) == 0 || strncmp(input, "reveal", 6) == 0) {
    command_processor__reveal(game);
    printf("%d ", x);
    printf("%d\n", y);
  } else if (strncmp(input, "f", 1) == 0 || strncmp(input, "flag", 4) == 0) {
    command_processor__flag(game);
  } else if (strncmp(input, "h", 1) == 0 || strncmp(input, "help", 4) == 0) {
    command_processor__help();
  } else {
    printf("Invalid Command\n"); // TODO: Change this when design is finalized
  } // if
  
} // game__takeGameInput
