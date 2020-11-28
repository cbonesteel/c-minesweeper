/**
 * @file game.c
 * @brief Implementation for the game functions.
 *
 * Source code for the game. This contains all the functions
 * needed to run the game, exceptt command processes.
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
#include <time.h>
#include "../../inc/board/board.h"
#include "../../inc/game/game.h"
#include "../../inc/game/command_processor.h"

/**
 * This function prints the win screen for the game.
 */
void game__print_win(struct Game *game) {
  FILE *fp;
  fp = fopen("resources/game/win.txt", "r");
  char buff[255];

  for (int i = 0; i < 10; ++i) {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff );
  } // for

  double board_size = board__get_x(&game->board) * board__get_y(&game->board);
  double turns_count = game->turns;
  
  double score = (board_size / turns_count) * 100.0;

  printf("%f", score);

  fclose(fp);
} // game__print_win

/**
 * This function prints the loss screen for the game.
 */
void game__print_loss() {
  FILE *fp;
  fp = fopen("resources/game/loss.txt", "r");
  char buff[255];

  for (int i = 0; i < 5; ++i) {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff );
  } // for
  
  fclose(fp);
} // game__print_loss

/**
 * This function builds a specified game. This function builds
 * the board to the specified size and difficulty. The won and noFog
 * params are set to false by default.
 * 
 * @param game the game to have it's board built
 */
void game__build_game(struct Game *game) {
  // TODO: Take input for board size
  game__set_end(false, game);
  board__build_array(10, 10, &game->board);
  
  /* Place mines randomly */
  srand(time(0)); // use time for better randomness
  
  for (int i = 0; i < 20; i++) { // TODO: Replace < 20 with density calculation
    bool placed = false;
    while (!placed) {
      int x = rand() % board__get_x(&game->board);
      int y = rand() % board__get_y(&game->board);
      placed = board__place_mine(x, y, &game->board);
    } // while
  } // for

  board__set_no_fog(false, &game->board);

  game->turns = 0;
  
  // TODO: Place mines based on settings
} // game__build_game

/**
 * This function prompts the user for game input. This function
 * then passes necessary information to the command processor to
 * be handled. Prints out invalid command information if command
 * is invalid.
 *
 * @param game the game to process input on
 */
void game__take_game_input(struct Game *game) {
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
      (strncmp(input, "r", 1) == 0 || strncmp(input, "f", 1) == 0 || strncmp(input, "g", 1) == 0)) {
    // Makes input invalid
    input = "x";
  } else if (strncmp(input, "r", 1) == 0 || strncmp(input, "f", 1) == 0 || strncmp(input, "g", 1) == 0) {
    // Sets x and y
    x = atoi(xChar);
    y = atoi(yChar);
  } // if

  // Processes Input by calling correct functions
  if (strncmp(input, "r", 1) == 0 || strncmp(input, "reveal", 6) == 0) {
    command_processor__reveal(x, y, game);
  } else if (strncmp(input, "f", 1) == 0 || strncmp(input, "flag", 4) == 0) {
    command_processor__flag(x, y, game);
  } else if (strncmp(input, "h", 1) == 0 || strncmp(input, "help", 4) == 0) {
    command_processor__help();
    game->turns--;
  } else if (strncmp(input, "g", 1) == 0 || strncmp(input, "guess", 5) == 0) {
    command_processor__guess(x, y, game);
  } else if (strncmp(input, "noFog", 5) == 0) {
    command_processor__no_fog(game);
  } else if (strncmp(input, "q", 1) == 0 || strncmp(input, "quit", 4) == 0) {
    command_processor__quit(game);
  } else if (strncmp(input, "c", 1) == 0 || strncmp(input, "close", 5) == 0) {
    command_processor__close(game);
  } else {
    printf("\nInvalid Command\n"); // TODO: Change when game design is finalized
    game->turns--;
  } // if

  game->turns++;
  
} // game__take_game_input

/**
 * This function runs the play loop for the passed in game.
 *
 * @param game the game to be played
 */
void game__play(struct Game *game) {
  while (!game__get_end(game)) {
    printf("\n");

    printf("Turn: %d\n", game->turns);
    if (board__get_no_fog(&game->board) == true) {
      board__print_no_fog(&game->board);
      board__set_no_fog(false, &game->board);
    } else {
      board__print_board(&game->board);
    } // if

    printf("\n");

    game__take_game_input(game);

    if (board__get_num_mines(&game->board) == 0 &&
        board__get_num_flags(&game->board) == 20) {
      // TODO: Change to check for number of flags for original num of mines
      game__print_win(game);
      game__set_end(true, game);
    } // if
  } // while
} // game__play

//---------------------//
//   GETTERS/SETTERS   //
//---------------------//

/**
 * This function takes in a bool and a game and sets
 * end status in game.
 *
 * @param end the end status
 * @param game the game to be set
 */
void game__set_end(bool end, struct Game *game) {
  game->end = end;
} // game__set_end

/**
 * This function takes in a game and returns it's end
 * variable.
 *
 * @param game the game to get the end status of
 *
 * @return the end status
 */
bool game__get_end(struct Game *game) {
  return game->end;
} // game__get_end
