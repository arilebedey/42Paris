/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:42:07 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/23 18:33:52 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**get_test_map(char **map)
{
	int		i;
	char	**test_map;

	i = 0;
	while (map[i])
		i++;
	test_map = malloc(sizeof(char *) * (i + 1));
	if (!test_map)
		malloc_error(map);
	i = 0;
	while (map[i])
	{
		test_map[i] = ft_strdup(map[i]);
		if (!test_map[i])
		{
			free_map(test_map);
			malloc_error(map);
		}
		i++;
	}
	test_map[i] = NULL;
	return (test_map);
}

static void	check_unvisited_elements(char **test_map, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (test_map[y])
	{
		x = 0;
		while (test_map[y][x])
		{
			if (test_map[y][x] == 'E' || test_map[y][x] == 'C')
			{
				free_map(test_map);
				map_error(map);
			}
			x++;
		}
		y++;
	}
}

static void	traverse_path(char **map, int x, int y)
{
	if (map[y] == NULL || map[y][x] == '\0' || y < 0 || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'B')
		return ;
	map[y][x] = 'V';
	traverse_path(map, x - 1, y);
	traverse_path(map, x + 1, y);
	traverse_path(map, x, y - 1);
	traverse_path(map, x, y + 1);
}

void	validate_path(char **map)
{
	char	**test_map;
	int		x;
	int		y;

	test_map = get_test_map(map);
	y = 0;
	while (test_map[y])
	{
		x = 0;
		while (test_map[y][x])
		{
			if (test_map[y][x] == 'P')
			{
				traverse_path(test_map, x, y);
				break ;
			}
			x++;
		}
		y++;
	}
	check_unvisited_elements(test_map, map);
	free_map(test_map);
}
