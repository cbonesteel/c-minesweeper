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

/* Global Variables */
extern bool running;

/**
 * This function processes a reveal command from the user. This function
 * takes in the x and y values of the square to be revealed as well as the
 * game to modify. It first checks the x and y values to ensure they are inbounds
 * for the board, if they are not, prints error message to the user and returns
 * false. Otherwise, the function checks if a mine is present on the tile, and
 * if one is, invokes the method to end the game loop and prints the losing
 * message. If one is not found, it will reveal the specified tile and return
 * true.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param game the game to be modified
 *
 * @return true if revealed sucessfully; false in all other cases
 */
bool command_processor__reveal(int x, int y, struct Game *game) {
  /* Checks if x and y are in bounds */
  if (x >= board__get_x(&game->board)) {
    printf("\nx is out of bounds\n"); // TODO: Change when game design is finalized
    return false;
  } else if (y >= board__get_y(&game->board)) {
    printf("\ny is out of bounds\n"); // TODO: Change when game design is finalized
    return false;
  } // if

  /* Check if there is a mine at the spot to be revealed */
  if (board__contains_mine(x, y, &game->board) == true) {
    game__set_end(true, game);
    game__print_loss();
    return false;
  } // if

  /* If all prior checks pass, reveal square*/
  board__reveal(x, y, &game->board);

  return true;
} // command_processor__reveal

/**
 * This function processes a flag command from the user. This function
 * takes in an x and a y as well as the game to be mofified. The function
 * first checks to ensure the x and y are in bounds. If they are not, it
 * prints a message to the user and returns false. Otherwise, it will check
 * if a mine is actually present and if one is, it will decrease the remaining
 * mines counter and the regardless flag the square and return true.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param game the game to be modified
 *
 * @return true if flagged; false otherwise
 */
bool command_processor__flag(int x, int y, struct Game *game) {
  /* Checks if x and y are in bounds */
  if (x > board__get_x(&game->board)) {
    printf("\nx is out of bounds\n"); // TODO: Change when game design is finalized
    return false;
  } else if (y > board__get_y(&game->board)) {
    printf("\ny is out of bounds\n"); // TODO: Change when game design is finalized
    return false;
  } // if

  /* Check if there is a mine at the spot to be flaged */
  if (board__contains_mine(x, y, &game->board) == true) {
    game->board.board_num_mines--;
  } // if

  /* If the in bounds check passes, flag square*/
  board__flag(x, y, &game->board);
  
  return true;
} // command_processor__flag

/**
 * This function processes a guess command from the user. This function
 * takes in an x and a y as well as the game to be modified. The function
 * first checks that x and y are in bounds. If they are not, it prints
 * an error message to the user and returns false. Otherwise, it will place 
 * a ? on a tile so long as it has not been revealed and return true.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @param game the game to be modified
 *
 * @return true if successful; false otherwise
 */
bool command_processor__guess(int x, int y, struct Game *game) {
  /* Checks if x and y are in bounds */
  if (x >= board__get_x(&game->board)) {
    printf("\nx is out of bounds\n"); // TODO: Change when game design is finalized
    return false;
  } else if (y >= board__get_y(&game->board)) {
    printf("\ny is out of bounds\n"); // TODO: Change when game design is finalized
    return false;
  } // if
  
  /* If all prior checks pass, guess square*/
  board__guess(x, y, &game->board);

  return true;
} // command_processor__guess

/**
 * This function prints the help screen for the user.
 */
void command_processor__help() {
  printf("Commands:\n");
  printf("\tr/reveal [row] [col]\tReveal a square\n");
  printf("\tm/mark [row] [col]\t\tFlag a square\n");
  printf("\tg/guess [row] [col]\t\tGuess a square");
  printf("\th/help        \t\tPrint help\n");
  printf("\tq/quit        \t\tQuit to menu");
  printf("\tc/close       \t\tQuit the program");
} // command_processor__help

/**
 * This function processes the noFog command from the user. This function
 * simply sets the no fog value for the board to true to be handled by the
 * game loop's print function. Returns true.
 *
 * @param game the game to be modified
 *
 * @return true
 */
bool command_processor__no_fog(struct Game *game) {
  board__set_no_fog(true, &game->board);
  
  return true;
} // command_processor__no_fog

/**
 * This function handles the game quitting to the main menu.
 *
 * @param game the game to be quit
 */
void command_processor__quit(struct Game *game) {
  game__set_end(true, game);
} // command_processor__quit

/**
 * This function handles the program closing completely.
 *
 * @param game the game to be quit
 */
void command_processor__close(struct Game *game) {
  game__set_end(true, game);
  running = false;
} // command_processor__close
