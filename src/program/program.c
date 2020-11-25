/**
 * @file program.c
 * @brief Implementation for the program functions.
 *
 * Doc
 *
 * @author Cameron Bonesteel
 * @date November 24, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/board/board.h"
#include "../../inc/game/game.h"
#include "../../inc/game/command_processor.h"
#include "../../inc/program/program.h"
#include "../../inc/menu/menu.h"

/* Global Variables */
bool running = true;

/**
 * This function runs the program loop to allow for
 * multiple games to be played in one run.
 */
void program__run() {
  menu__print_welcome();

  bool gameRan;
  
  while(running) {
    gameRan = menu__take_input();
    if (gameRan == false && running == true) {
      running = false;
    } else if (gameRan == true && running == false) {
      running = false;
    } else {
      running = true;
    } // else
  } // while
} // program__run
