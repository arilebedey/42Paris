/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:27:43 by agense            #+#    #+#             */
/*   Updated: 2025/02/05 20:01:35 by agense           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_buff	i_buff(t_buff *buff_pt)
{
	int		i;

	buff_pt->size = 1000000;
	buff_pt->str = malloc(sizeof(char) * 1000000);
	i = -1;	
	while (++i < buff_pt->size)
		(buff_pt->str)[i] = 0;
	return (*buff_pt);
}

void	clean_buff(t_buff buff)
{
	int	i;

	i = -1;
	while (++i < 1000000)
		buff.str[i] = 0;/*
	while (buff.str[++i])
		buff.str[i] = 0;*/
}
