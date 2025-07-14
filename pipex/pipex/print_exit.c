/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:56:56 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/11 22:25:03 by alebedev         ###   ########.fr       */
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

void	print_error_exit(t_pipex *ctx, char *err)
{
	print_error(err);
	free_pipex(ctx);
	exit(1);
}

void	print_sys_error_exit(t_pipex *ctx, char *err)
{
	perror(err);
	free_pipex(ctx);
	exit(1);
}
