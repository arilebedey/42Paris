/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:44:20 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/24 16:44:21 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	err_too_many_args(void)
{
	ft_puterr("Too many arguments.\n");
}

void	err_no_arg(void)
{
	ft_puterr("File name missing.\n");
}

void	err_not_file(void)
{
	ft_puterr("Cannot read file.\n");
}
