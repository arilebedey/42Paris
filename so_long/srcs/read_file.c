/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:38:04 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/24 17:54:57 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

char	**file_to_map(int fd)
{
	char	**map;
	char	**tmp;
	char	*line;
	int		count;
	int		i;

	count = 0;
	line = get_next_line(fd);
	while (lines)
	{
		tmp = malloc(sizeof(int) * (count + 2));
		if (!tmp)
	}
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
	{
		ft_putstr_fd("Error\nCannot read file\n", 2);
		exit(1);
	}
	close(fd);
	return (map);
}
