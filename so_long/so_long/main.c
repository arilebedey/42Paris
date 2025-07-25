/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:32:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/21 18:22:58 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_argc(argc, argv[1]);
	game.map = read_file(argv[1]);
	parse_map(&game);
	game.current_frame = 0;
	game.moves_count = 0;
	init_game(&game);
	mlx_key_hook(game.win, on_key_press, &game);
	mlx_loop_hook(game.mlx, update_animation, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	destroy_game(&game);
	return (EXIT_SUCCESS);
}
