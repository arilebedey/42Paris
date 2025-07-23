/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:18:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/23 18:30:19 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	file_format_error(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		exit(1);
	}
}

void	malloc_error(char **map)
{
	if (map)
		free_map(map);
	ft_putstr_fd("Error\nMalloc error\n", 2);
	exit(1);
}

void	file_read_error(int fd)
{
	close(fd);
	ft_putstr_fd("Error\nCannot read file\n", 2);
	exit(1);
}

void	map_error(char **map)
{
	if (map)
		free_map(map);
	ft_putstr_fd("Error\nMap error\n", 2);
	exit(1);
}
