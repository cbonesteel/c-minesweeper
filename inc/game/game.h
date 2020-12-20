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

struct Game {
  struct Board board;
  bool end;
  int turns;
  int flags_needed;
}; // Game

void game__print_win(struct Game *game);
void game__print_loss();
void game__build_game(int x, int y, int mines, struct Game *game);
void game__take_game_input(struct Game *game);
void game__play(struct Game *game);

// getters/setters
void game__set_end(bool end, struct Game *game);
bool game__get_end(struct Game *game);
void game__set_flags(int flags, struct Game *game);
int game__get_flags(struct Game *game);

#endif // GAME_H
