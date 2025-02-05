/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 22:34:54 by agense            #+#    #+#             */
/*   Updated: 2025/02/05 21:11:43 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//Check si la taille de la ligne info (contenu dans le buffer)
//contient le nombre d infos minimum
int	check_info_size(t_buff buff)
{
	int	i;

	i = 0;
	while (buff.str[i] != 0 && buff.str[i] != '\n')
		i++;
	if (i < 4)
		return (0);
	return (1);
}

//Check la validite des infos
int	check_info_validity(char *info)
{
	int	i;
	int	j;

	i = -1;
	while (info[++i])
	{
		j = -1;
		while (info[++j])
		{
			if (info[i] == info[j] && i != j)
				return (0);
		}
	}
	return (1);
}

// Prend les 3 derniers caracteres de la ligne info (caracteres de la map)
char	*take_info(t_buff buff, int *lign_info)
{
	int		i;
	char	*info;
	char	*lign_info_str;

	lign_info_str = malloc(sizeof(char) * (ft_strlen(buff.str) - 3));
	info = malloc(sizeof(char) * 3);
	info[2] = buff.str[ft_strlen(buff.str) - 1];
	info[1] = buff.str[ft_strlen(buff.str) - 2];
	info[0] = buff.str[ft_strlen(buff.str) - 3];
	if (!is_printable(info[0]) || !is_printable(info[1]) || !is_printable(info[2]))
		return (0);
	i = -1;
	while (++i < ft_strlen(buff.str) - 3)
		lign_info_str[i] = buff.str[i];
	i = 0;
	while (lign_info_str[i] == buff.str[i])
	{
		if (!(is_nbr(lign_info_str[i])))
		{
			free(lign_info_str);
			return (0);
		}
		i++;
	}
	*lign_info = ft_atoi(lign_info_str);
	free(lign_info_str);
	if (check_info_validity(info))
		return (info);
	else
		return (0);
}

int	put_info_in_buf(t_buff buff, int fd)
{
	int		i;
	int		f_bytes_read;
	char	c[1];

	i = -1;
	f_bytes_read = 1;
	while (f_bytes_read > 0)
	{
		f_bytes_read = read(fd, c, 1);
		if (c[0] == '\n')
		{
			buff.str[++i] = 0;
			break ;
		}
		buff.str[++i] = c[0];
	}
	return (check_info_size(buff));
}

int	term_put_info_in_buf(t_buff buff)
{
	int		i;
	int		f_bytes_read;
	char	c[1];

	i = -1;
	f_bytes_read = 1;
	while ((f_bytes_read > 0))
	{
		f_bytes_read = read(0, c, 1);
		if (c[0] == '\n')
		{
			buff.str[++i] = 0;
			break ;
		}
		buff.str[++i] = c[0];
	}
	return (check_info_size(buff));
}
