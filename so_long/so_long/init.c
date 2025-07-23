/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:41:24 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/23 18:30:10 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argc(int argc, char *file)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\nNo map given\n", 2);
		exit(1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments\n", 2);
		exit(1);
	}
	file_format_error(file);
}

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
