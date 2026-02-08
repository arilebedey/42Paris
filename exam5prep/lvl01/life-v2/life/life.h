#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game {
  int width;
  int height;
  int iter;
  char alive;
  char dead;
  int i;
  int j;
  int draw;
  char **board;
} t_game;

void print_board(t_game *game);
void free_board(t_game *game);
void free_tmp(t_game *game, char **tab);
int init_game(t_game *game, char **av);
void fill_board(t_game *game);
int play_game(t_game *game);

#endif
