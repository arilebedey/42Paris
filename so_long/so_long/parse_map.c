/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:06:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/02 19:07:40 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	check_rectangular(char **map)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(char **map)
{
	int	x_max;
	int	y_max;
	int	i;

	i = 0;
	x_max = ft_strlen(map[0]) - 1;
	y_max = 0;
	while (map[y_max])
		y_max++;
	while (i < x_max - 1)
	{
		if (map[0][i] != '1' || map[y_max - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < y_max - 1)
	{
		if (map[i][0] != '1' || map[i][x_max - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	parse_map(t_game *game)
{
	parse_chars(game);
	if (!check_rectangular(game->map))
		map_error(game->map);
	if (!check_walls(game->map))
		map_error(game->map);
	validate_path(game->map);
}
