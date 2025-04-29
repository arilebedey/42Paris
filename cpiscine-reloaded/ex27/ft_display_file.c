/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:44:24 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/24 16:56:18 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	check_errors(int ac)
{
	if (ac == 1)
	{
		err_no_arg();
		return (0);
	}
	if (ac > 2)
	{
		err_too_many_args();
		return (0);
	}
	return (1);
}

int	openfile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

int	display_file(int fd)
{
	char	buffer[4096];
	int		bytes_read;

	bytes_read = read(fd, buffer, 4096);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, 4096);
	}
	if (bytes_read < 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	fd;

	if (!check_errors(ac))
		return (0);
	fd = openfile(av[1]);
	if (fd < 0)
	{
		err_not_file();
		return (0);
	}
	if (!display_file(fd))
	{
		err_not_file();
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
