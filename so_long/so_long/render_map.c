/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:50:26 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/18 20:45:20 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	put_count(t_game *game)
{
	char	*tmp;

	tmp = ft_itoa(game->moves_count);
	if (!tmp)
		malloc_error_late(game);
	mlx_string_put(game->mlx, game->win, 20, 40, 0xFFFFFF, tmp);
	free(tmp);
}

static void	render_map2(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img[game->current_frame], x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->map[y][x] == 'e')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_open, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'M')
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x + 1])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit_closed, x * TILE_SIZE, y * TILE_SIZE);
			else
				render_map2(game, x, y);
			x++;
		}
		y++;
	}
	put_count(game);
}
