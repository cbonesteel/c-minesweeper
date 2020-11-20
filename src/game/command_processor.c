/**
 * @file command_processor.c
 * @brief Implementation for command processes.
 *
 * Doc
 *
 * @author
 * @date November 11, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/board/board.h"
#include "../../inc/game/game.h"
#include "../../inc/game/command_processor.h"

/**
 * 
 */
bool command_processor__reveal(int x, int y, struct Game *game) {
  /* Checks if x and y are in bounds */
  if (x > board__get_x(&game->board)) {
    printf("x is out of bounds\n"); // TODO: Change when game design is finalized
  } else if (y > board__get_y(&game->board)) {
    printf("y is out of bounds\n"); // TODO: Change when game design is finalized
  } // if

  /* Check if there is a mine at the spot to be revealed */
  if (board__contains_mine(x, y, &game->board) == true) {
    // TODO: Make Lose Function to end game loop
    game__printLoss();
    return false;
  } // if

  /* If all prior checks pass, reveal square*/
  board__reveal(x, y, &game->board);

  return false;
} // command_processor__reveal

/**
 * 
 */
bool command_processor__flag(int x, int y, struct Game *game) {
  // TODO: Add Implementation
  return false;
} // command_processor__flag

/**
 * This function prints the help screen for the user.
 */
void command_processor__help() {
  printf("Commands:\n");
  printf("\tr/reveal [x] [y]\tReveal a square\n");
  printf("\tm/mark [x] [y]\t\tFlag a square\n");
  printf("\th/help        \t\tPrint help\n");
} // command_processor__help

/**
 *
 */
bool command_processor__noFog(int x, int y, struct Game *game) {
  // TODO: Add Implementation
  return false;
} // command_processor__noFog
