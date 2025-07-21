/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:41:24 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/21 18:12:52 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		mlx_init_error(game);
	width = ft_strlen(game->map[0]) - 1;
	while (game->map[height])
		height++;
	game->win = mlx_new_window(game->mlx, width * TILE_SIZE, height * TILE_SIZE,
			"alebedev's 42 so_long project!");
	if (!game->win)
		mlx_init_error(game);
	load_images(game);
	render_map(game);
}
