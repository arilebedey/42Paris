/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:33:14 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/02 23:34:02 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		collectible_count;
	bool	enemy_is_alive;
	int		sprite_frame;
	int		moves_count;
}			t_game;

// error.c
void		check_argc(int argc, char *file);
void		malloc_error(char **map);
void		file_read_error(void);
void		map_error(char **map);

// free.c
void		free_map(char **map);

// read_file.c
char		**read_file(char *file);

// parse_map.c
void		parse_map(t_game *game);

// parse_chars.c
void		parse_chars(t_game *game);

// enemy.c
bool		check_enemy(char **map);

// validate_path.c
void		validate_path(char **map);

#endif
