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
bool command_processor__reveal(struct Game *game) {
  // TODO: Add Implementation
  return false;
} // command_processor__reveal

/**
 *
 */
bool command_processor__flag(struct Game *game) {
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
bool command_processor__noFog(struct Game *game) {
  // TODO: Add Implementation
  return false;
} // command_processor__noFog
