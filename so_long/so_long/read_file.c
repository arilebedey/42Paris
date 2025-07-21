/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:38:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/21 17:55:53 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	free_read(char **map)
{
	free_map(map);
	malloc_error(map);
}

static void	fill_tmp(char **map, char **tmp, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		tmp[i] = map[i];
		i++;
	}
}

static char	**append_line(char **map, char *line, int count)
{
	char	**tmp;

	tmp = malloc(sizeof(char *) * (count + 2));
	if (!tmp)
		free_read(map);
	fill_tmp(map, tmp, count);
	tmp[count] = line;
	tmp[count + 1] = NULL;
	if (map)
		free(map);
	return (tmp);
}

char	**file_to_map(int fd)
{
	char	**map;
	char	*line;
	int		count;

	map = NULL;
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		map = append_line(map, line, count);
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
		file_read_error(fd);
	map = file_to_map(fd);
	if (!map)
		file_read_error(fd);
	close(fd);
	return (map);
}
