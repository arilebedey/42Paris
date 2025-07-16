/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:48:02 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/23 17:17:38 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

void	perror_exit(char *err)
{
	perror(err);
	exit(1);
}
