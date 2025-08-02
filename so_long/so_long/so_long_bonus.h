/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:33:14 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/02 20:48:18 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		current_frame;
	bool	enemy_is_alive;
	int		moves_count;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit_open;
	void	*img_exit_closed;
	void	*img_enemy;
	int		collectible_count;
	int		collectible_frame;
	void	**collectible_img;
}			t_game;

// error.c
void		check_argc(int argc, char *file);
void		malloc_error(char **map);
void		file_read_error(int fd);
void		map_error(char **map);

// error2.c
void		mlx_init_error(t_game *game);
void		img_load_error(t_game *game);
void		malloc_error_late(t_game *game);

// free.c
void		free_map(char **map);
void		free_game_early(t_game *game);

// read_file.c
char		**read_file(char *file);

// parse_map.c
void		parse_map(t_game *game);

// parse_chars.c
void		parse_chars(t_game *game);

// enemy.c
bool		check_enemy(char **map);
void		move_enemy(t_game *game, int *enemy_direction);

// validate_path.c
void		validate_path(char **map);

// init.c
void		init_game(t_game *game);

// load_images.c
void		load_images(t_game *game);

// render_map.c
void		render_map(t_game *game);

// on_key_press.c
int			on_key_press(int key, t_game *game);

// on_gameplay.c
void		record_new_move(t_game *game);
void		on_hit_enemy(t_game *game);
void		on_hit_collectible(t_game *game, int new_y, int new_x);
void		on_game_complete(t_game *game);

// change_state.c
void		open_game_exit(char **map);

// update_animation.c
int			update_animation(t_game *game);

// close_game.c
int			destroy_game(t_game *game);

#endif
