/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:32:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/04 21:21:24 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	init_game(t_game *game)
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
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_argc(argc, argv[1]);
	game.map = read_file(argv[1]);
	parse_map(&game);
	game.sprite_frame = 0;
	game.moves_count = 0;
	init_game(&game);
	//
	return (EXIT_SUCCESS);
}
