/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:51:57 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/18 20:44:40 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	find_enemy(char **map, int *y, int *x)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
			{
				*y = i;
				*x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	is_player_on_enemy(t_game *game, int new_y, int enemy_x)
{
	if (game->map[new_y][enemy_x] == 'P')
		on_hit_enemy(game);
}

bool	check_enemy(char **map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x++] == 'M')
				count++;
		}
		y++;
	}
	if (count == 1)
		return (true);
	return (false);
}

void	move_enemy(t_game *game, int *enemy_direction)
{
	int	enemy_x;
	int	enemy_y;
	int	next_y;
	int	new_y;

	find_enemy(game->map, &enemy_y, &enemy_x);
	if (!*enemy_direction)
		next_y = 1;
	else
		next_y = -1;
	new_y = enemy_y + next_y;
	if (game->map[new_y][enemy_x] == '1' || game->map[new_y][enemy_x] == 'E'
		|| game->map[new_y][enemy_x] == 'C')
	{
		if (!*enemy_direction)
			*enemy_direction = 1;
		else
			*enemy_direction = 0;
		return ;
	}
	game->map[enemy_y][enemy_x] = '0';
	is_player_on_enemy(game, new_y, enemy_x);
	game->map[new_y][enemy_x] = 'M';
	render_map(game);
}
