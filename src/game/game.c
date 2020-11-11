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
} // printWelcome

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
} // printWin

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
} // printLoss

/**
 * This function prompts the user for game input. This function
 * then passes necessary information to the command processor to
 * be handled.
 */
void game__takeGameInput() {

} // takeGameInput
