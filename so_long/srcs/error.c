/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:18:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/24 17:54:48 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	malloc_error(char **map)
{
	if (map)
		free_map(map);
	ft_printf("Error\nProblème d'allocation mémoire\n");
	exit(1);
}

void	file_read_error(void)
{
	ft_putstr_fd("Error\nCannot read file\n", 2);
	exit(1);
}

static void	file_format_error(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		exit(1);
	}
}

void	arg_error(int argc, char *file)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error\nNo map given\n", 2);
		exit(1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments\n", 2);
		exit(1);
	}
	file_format_error(file);
}
