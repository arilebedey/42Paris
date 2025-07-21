/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:09:37 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/21 19:07:31 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static int	check_collectible(char **map)
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
			if (map[y][x++] == 'C')
				count++;
		}
		y++;
	}
	return (count);
}

static int	check_exit(char **map)
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
			if (map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

static int	check_player(char **map)
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
			if (map[y][x++] == 'P')
				count++;
		}
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

static int	check_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != 'P' && map[y][x] != '0' && map[y][x] != 'E'
				&& map[y][x] != '1' && map[y][x] != 'C' && map[y][x] != '\n'
				&& map[y][x] != 'M')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	parse_chars(t_game *game)
{
	game->collectible_count = check_collectible(game->map);
	if (!game->collectible_count)
		map_error(game->map);
	if (!check_exit(game->map))
		map_error(game->map);
	if (!check_player(game->map))
		map_error(game->map);
	if (!check_chars(game->map))
		map_error(game->map);
	game->enemy_is_alive = check_enemy(game->map);
	if (!game->enemy_is_alive)
		map_error(game->map);
}
