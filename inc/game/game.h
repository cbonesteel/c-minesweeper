/**
 * @file game.h
 * @brief The header for game.
 */

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../board/board.h"
// #include "command_processor.h"

struct Game {
  struct Board board;
  bool noFog;
  bool won;
}; // Game

void game__printWelcome();
void game__printWin();
void game__printLoss();
void game__buildGame(struct Game *game);
void game__takeGameInput(struct Game *game);



#endif // GAME_H
