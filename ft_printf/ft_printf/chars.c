/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:58:21 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/01 10:58:22 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		count += ft_print_char(str[i++]);
	return (i);
}
