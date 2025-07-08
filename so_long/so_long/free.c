/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:53:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/08 22:38:12 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	destroy_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectible_frame)
	{
		mlx_destroy_image(game->mlx, game->collectible_img[i]);
		i++;
	}
	free(game->collectible_img);
}

void	free_game_early(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit_open)
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->img_exit_closed)
		mlx_destroy_image(game->mlx, game->img_exit_closed);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	if (game->collectible_img)
		destroy_collectible(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
}

void	destroy_game(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_exit_open);
	mlx_destroy_image(game->mlx, game->img_exit_closed);
	if (game->img_enemy)
		mlx_destroy_image(game->mlx, game->img_enemy);
	i = 0;
	while (i < game->collectible_frame)
	{
		mlx_destroy_image(game->mlx, game->collectible_img[i]);
		i++;
	}
	free(game->collectible_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	free(game->mlx);
	exit(0);
}
