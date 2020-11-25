/**
 * @file menu.h
 * @brief The header for menu.
 */

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../game/game.h"
#include "../game/command_processor.h"
#include "../board/board.h"

bool menu__take_input();
void menu__print_welcome();

#endif // MENU_H
