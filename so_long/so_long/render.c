/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 21:30:49 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/04 23:33:54 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	img_size;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm",
			&img_size, &img_size);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./imgs/enemy.xpm",
			&img_size, &img_size);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "./imgs/floor.xpm",
			&img_size, &img_size);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./imgs/player.xpm",
			&img_size, &img_size);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit_open.xpm", &img_size, &img_size);
	game->img_exit_closed = mlx_xpm_file_to_image(game->mlx,
			"./imgs/exit_closed.xpm", &img_size, &img_size);
	if (!game->img_wall || !game->img_player || !game->img_floor
		|| !game->img_exit_open || !game->img_exit_closed || !game->img_enemy)
		img_load_error(game);
	load_collectible(game, img_size);
}
