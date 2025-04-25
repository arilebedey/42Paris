/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:22:55 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/05 21:58:46 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	*frst_testable(char **map, char *info)
{
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	pos[0] = 0;
	pos[1] = 0;
	while (pos[0] <= getmapidx(map) && pos[1] <= getlineidx(map))
	{
		if (map[pos[0]][pos[1]] == info[0])
			return (pos);
		if (pos[1] == getlineidx(map))
		{
			pos[0]++;
			pos[1] = 0;
		}
		else
			pos[1]++;
	}
	pos[0] = -1;
	pos[1] = -1;
	return (pos);
}

int	*last_testable(char **map, char *info)
{
	int	*pos;
	int	last_map_idx;

	last_map_idx = getmapidx(map);
	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	pos[0] = getmapidx(map);
	pos[1] = getlineidx(map);
	while (pos[0] >= 0 && pos[1] >= 0)
	{
		if (map[pos[0]][pos[1]] == info[0])
			return (pos);
		if (pos[1] == 0)
		{
			pos[0]--;
			pos[1] = getmapidx(map);
		}
		else
			pos[1]--;
	}
	pos[0] = -1;
	pos[1] = -1;
	return (pos);
}

int	is_last(int y, int x, int *last)
{
	if (y == last[0] && x == last[1])
		return (1);
	return (0);
}

int	*ft_next_testable(char **map, int *pos, char *info, int was_incremented)
{
	if (pos[0] == -1)
	{
		if (!last_testable(map, info))
			return (0);
		pos[0] = 0;
		pos[1] = 0;
	}
	if (is_last(pos[0], pos[1], last_testable(map, info)))
		return (0);
	while (pos[0] <= getmapidx(map) && pos[1] <= getlineidx(map))
	{
		if (map[pos[0]][pos[1]] == info[0] && was_incremented != 0)
			return (pos);
		if (pos[1] == getlineidx(map))
		{
			if (pos[0] == getmapidx(map))
				return (0);
			(pos[0])++;
			pos[1] = 0;
		}
		else
			pos[1]++;
		was_incremented++;
	}
	return (pos);
}

int	max_steps(char **map, char *info)
{
	int	i;
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	if (!last_testable(map, info))
		return (0);
	pos = frst_testable(map, info);
	i = 0;
	i++;
	while (!is_last(pos[0], pos[1], last_testable(map, info)) || \
			(pos[0] == -1))
	{
		pos = ft_next_testable(map, pos, info, 0);
		if (!pos)
			return (0);
		i++;
	}
	free(pos);
	return (i);
}
