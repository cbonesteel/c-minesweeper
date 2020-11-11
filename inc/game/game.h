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
#include "command_processor.h"

void game__printWelcome();
void game__printWin();
void game__printLoss();
void game__takeGameInput();



#endif // GAME_H
