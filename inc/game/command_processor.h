/**
 * @file command_processor.h
 * @brief The header for command processor.
 */

#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../board/board.h"
#include "game.h"

bool command_processor__reveal(struct Game *game);
bool command_processor__flag(struct Game *game);
void command_processor__help();
bool command_processor__noFog(struct Game *game);


#endif // COMMAND_PROCESSOR_H
