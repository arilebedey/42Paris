/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:17:03 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:28:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

int	print_warn(char *err)
{
	write(2, err, ft_strlen(err));
	return (0);
}

int	print_error(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}
