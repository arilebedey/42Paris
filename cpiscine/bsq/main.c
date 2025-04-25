/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:28:00 by agense            #+#    #+#             */
/*   Updated: 2025/02/05 21:29:28 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (++i < count_lines(*map))
		free(map[i]);
	free(map);
}

int	main(int ac, char **av)
{
	int		i;
	int		y;
	t_buff	buff;
	char	**map;
	char	*info;
	int	lign_info;
	int	fd;
	
	map = 0;
	buff = i_buff(&buff);
	
	fd = 0;
	t_bsq	sqr;
	sqr.y = 0;
	sqr.x = 0;
	sqr.size = 1;
	if (ac > 1)
	{
		// Si au moins un fichier est donne en parametres
		i = 0;
		while (++i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (!put_info_in_buf(buff, fd))
			{
				write(1, "info in buff\n", 13);
				clean_buff(buff);
				write_error();
				close(fd);
				continue;
			}
			info = take_info(buff, &lign_info);
			if (!info)
			{	
				write(1, "info\n", 5);
				clean_buff(buff);
				close(fd);
				write_error();
				continue ;
			}
			clean_buff(buff);
			map = i_map(&map, buff, fd, info);
			if (!map)
			{
				write(1, "map\n", 4);
				clean_buff(buff);
				close(fd);
				write_error();
				continue ;
			}
			y = -1;
			while (map[++y])
				;
			if (y != lign_info)
			{
				printf("%d\n", y);
				printf("%d\n", lign_info);
				write(1, "y != lign_info\n",10);
				clean_buff(buff);
				close(fd);
				write_error();
				continue ;
			}
			close(fd);

			t_bsq	sqr;
			sqr = ft_find(map, info);
			if (sqr.x == -1)
			{
				clean_buff(buff);
				close(fd);
				write_error();
				continue;
			}
			print_map(map);
			max_steps(map, info);
			printf("\n");
			put_sq_in_map(map, sqr, info);
			print_map(map);
			free(info);
			clean_buff(buff);
		}
	}
	else
	{
		// Si aucun fichier n'est donnee -> lecture du terminal
		if (!term_put_info_in_buf(buff))
		{
			clean_buff(buff);
			write_error();
			return (0);
		}
		info = take_info(buff, &lign_info);
		if (!info)
		{	
			clean_buff(buff);
			write_error();
			return (0);
		}
		map = term_i_map(&map, buff, info);
		if (!map)
		{
			clean_buff(buff);
			write_error();
			return (0);
		}
		y = -1;
		while (map[++y])
			;
		if (y != lign_info)
		{
			clean_buff(buff);
			close(fd);
			write_error();
			return (0);
		}
		put_sq_in_map(map, sqr, info);
		print_map(map);
		free(info);
	}
	if (!(!map))
		free_map(map);
	free(buff.str);
	return (0);
}
/*
			// tests d'ari
			int *pos;
			pos = last_testable(map, info);
			printf("y: %i x: %i <-- last testable result\n", pos[0], pos[1]);
			ft_next_testable(map, pos, info, 0);
			printf("y: %i x: %i <-- init, position++\n", pos[0], pos[1]);
			printf("%i <-- max steps\n", max_steps(map, info));
			printf("y: %i x: %i size: %i <-- BSQ\n", sqr.y, sqr.x, sqr.size);
			// fin des tests d'ari
*/
