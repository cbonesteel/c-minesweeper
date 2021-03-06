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
#include <math.h>
#include "../../inc/board/board.h"
#include "../../inc/game/game.h"
#include "../../inc/game/command_processor.h"
#include "../../inc/menu/menu.h"

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
    menu__build_board(&game);
    return true;
  } // if
  
} // menu__take_input

/**
 * This function takes in a game and asks the user for height, width and density
 * paramaters. Then it builds the game.
 *
 * @param game the game to be built
 * 
 * @return true if runs; false otherwise
 */
bool menu__build_board(struct Game *game) {
  char input[5];

  int height = -1;
  int width = -1;
  int num_mines = -1;
  
  bool valid = false;

  while (!valid) {
    printf("\nEnter Height (Max 24): ");
    fgets(input, 5, stdin);
    height = atoi(input);
    if (height < 25 && height > 1) {
      valid = true;
    } else {
      printf("\nInvalid Height, try again\n");
    } // if
  } // while

  valid = false;

  while (!valid) {
    printf("\nEnter Width (Max 32): ");
    fgets(input, 5, stdin);
    width = atoi(input);
    if (width < 33 && width > 1) {
      valid = true;
    } else {
      printf("\nInvalid Width, try again\n");
    } // if
  } // while

  valid = false;

  while (!valid) {
    printf("\nEnter Mines (Up to 26 percent of board area, max 200): ");
    fgets(input, 5, stdin);
    num_mines = atoi(input);
    if (num_mines < ceil((height * width) * .261) && num_mines > 0) {
      valid = true;
    } else {
      printf("\nInvalid Number of Mines, try again\n");
    } // if
  } // while
  
  game__build_game(width, height, num_mines, game);
  game__play(game);

  return true;
  
} // menu__build_baord

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
