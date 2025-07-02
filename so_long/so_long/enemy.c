/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:51:57 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/01 22:53:27 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
