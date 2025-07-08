/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:10:12 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/08 22:38:12 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	get_player_coords(char **map, int *y, int *x)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				*y = row;
				*x = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

static void	on_move_player(t_game *game, int to_x, int to_y)
{
	int	current_x;
	int	current_y;
	int	new_x;
	int	new_y;

	get_player_coords(game->map, &current_x, &current_y);
	new_x += to_x;
	new_y += to_y;
	if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E')
		return ;
	if (game->map[new_y][new_x] == 'M')
		on_hit_enemy(game);
	if (game->map[new_y][new_x] == 'C')
		on_hit_collectible(game, new_y, new_x);
	if (game->map[new_y][new_x] == 'e')
	{
		on_game_complete(game);
		return ;
	}
	count_moves(game);
	game->map[current_x][current_y] = '0';
	game->map[new_y][new_x] = 'P';
	render_map(game);
}

int	on_key_press(int key, t_game *game)
{
	if (key == 65307)
	{
		free_game_early(game);
		exit(0);
	}
	if (key == 97)
		on_move_player(game, 0, -1);
	if (key == 100)
		on_move_player(game, 0, 1);
	if (key == 115)
		on_move_player(game, 1, 0);
	if (key == 119)
		on_move_player(game, -1, 0);
	return (0);
}
