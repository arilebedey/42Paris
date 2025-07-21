/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:55:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/21 16:59:58 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	close_game(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit_closed);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_exit_open);
	mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	i = 0;
	while (i < game->collectible_count)
		mlx_destroy_image(game->mlx, game->collectible_img[i++]);
	free(game->collectible_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	free(game->mlx);
	exit(0);
}
