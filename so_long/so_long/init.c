/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:41:24 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/08 16:47:06 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_init_error(game);
	while (game->map[height])
		height++;
	game->win = mlx_new_window(game->mlx, width * TILE_SIZE, height * TILE_SIZE,
			"alebedev's 42 so_long project!");
	if (!game->win)
		mlx_init_error(game);
	load_images(game);
	render_map(game);
}
