#include "life.h"

void print_board(t_game *game) {
  for (int i = 0; i < game->height; i++) {
    for (int j = 0; j < game->width; j++) {
      putchar(game->board[i][j]);
    }
    putchar('\n');
  }
}

void free_tmp(t_game *game, char **tab) {
  if (tab) {
    for (int i = 0; i < game->height; i++) {
      if (tab[i]) {
        free(tab[i]);
      }
    }
    free(tab);
  }
}

void free_board(t_game *game) {
  if (game->board) {
    for (int i = 0; i < game->height; i++) {
      if (game->board[i]) {
        free(game->board[i]);
      }
    }
    free(game->board);
  }
}

int init_game(t_game *game, char **av) {
  game->alive = 'O';
  game->dead = ' ';
  game->width = atoi(av[1]);
  game->height = atoi(av[2]);
  game->iter = atoi(av[3]);
  game->i = 0;
  game->j = 0;
  game->draw = 0;
  game->board = malloc(sizeof(char *) * (game->height));
  if (!game->board)
    return 1;
  for (int i = 0; i < game->height; i++) {
    game->board[i] = malloc(sizeof(char) * (game->width));
    if (!game->board[i]) {
      free_board(game);
      return 1;
    }
    for (int j = 0; j < game->width; j++)
      game->board[i][j] = ' ';
  }
  return (0);
}

void fill_board(t_game *game) {
  char buffer;
  int flag;
  while (read(0, &buffer, 1) == 1) {
    flag = 0;
    switch (buffer) {
    case 'w':
      if (game->i > 0)
        game->i--;
      break;
    case 'a':
      if (game->j > 0)
        game->j--;
      break;
    case 's':
      if (game->i < game->height - 1)
        game->i++;
      break;
    case 'd':
      if (game->j < game->width - 1)
        game->j++;
      break;
    case 'x':
      game->draw = !(game->draw);
      break;
    default:
      flag = 1;
    }

    if (game->draw && (flag == 0)) {
      game->board[game->i][game->j] = game->alive;
    }
  }
}

int count_neighbors(t_game *game, int i, int j) {
  int count = 0;
  for (int di = -1; di < 2; di++) {
    for (int dj = -1; dj < 2; dj++) {
      if ((di == 0) && (dj == 0))
        continue;
      int ni = di + i;
      int nj = dj + j;
      if ((ni >= 0) && (ni < game->height) && (nj >= 0) && (nj < game->width)) {
        if (game->board[ni][nj] == game->alive)
          count++;
      }
    }
  }
  return count;
}

int play_game(t_game *game) {
  char **tmp;
  tmp = malloc(sizeof(char *) * (game->height));
  if (!tmp)
    return 1;
  for (int i = 0; i < game->height; i++) {
    tmp[i] = malloc(sizeof(char) * (game->width));
    if (!tmp[i]) {
      free_tmp(game, tmp);
      return 1;
    }
  }

  for (int i = 0; i < game->height; i++) {
    for (int j = 0; j < game->width; j++) {
      int count = count_neighbors(game, i, j);
      if (game->board[i][j] == game->alive) {
        if ((count == 2) || (count == 3))
          tmp[i][j] = game->alive;
        else
          tmp[i][j] = game->dead;
      } else {
        if (count == 3)
          tmp[i][j] = game->alive;
        else
          tmp[i][j] = game->dead;
      }
    }
  }

  free_board(game);
  game->board = tmp;
  return 0;
}

int main(int ac, char **av) {
  if (ac != 4)
    return 1;

  t_game game;

  if (init_game(&game, av))
    return 1;
  fill_board(&game);
  for (int i = 0; i < game.iter; i++) {
    if (play_game(&game)) {
      free_board(&game);
      return 1;
    }
  }
  print_board(&game);
  free_board(&game);
  return 0;
}
