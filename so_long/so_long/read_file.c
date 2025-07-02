/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:38:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/26 15:03:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

static void	fill_tmp(int i, char **map, char **tmp, int count)
{
	i = 0;
	while (i < count)
	{
		tmp[i] = map[i];
		i++;
	}
}

char	**file_to_map(int fd)
{
	char	**map;
	char	**tmp;
	char	*line;
	int		count;
	int		i;

	map = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmp = malloc(sizeof(int) * (count + 2));
		if (!tmp)
			malloc_error(map);
		fill_tmp(i, map, tmp, count);
		tmp[count] = line;
		tmp[count + 1] = NULL;
		if (map)
			free(map);
		map = tmp;
		count++;
		line = get_next_line(fd);
	}
	return (map);
}

char	**read_file(char *file)
{
	char	**map;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		file_read_error();
	map = file_to_map(fd);
	if (!map)
		file_read_error();
	close(fd);
	return (map);
}
