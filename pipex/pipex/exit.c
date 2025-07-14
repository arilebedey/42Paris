/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:56:56 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/15 22:50:24 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	print_error_exit(t_pipex *ctx, char *err)
{
	print_error(err);
	free_pipex(ctx);
	exit(1);
}

void	print_error_exit_code(t_pipex *ctx, char *err, int exit_code)
{
	print_error(err);
	free_pipex(ctx);
	exit(exit_code);
}

void	print_perror_exit(t_pipex *ctx, char *err)
{
	perror(err);
	free_pipex(ctx);
	exit(1);
}

void	print_perror_exit_code(t_pipex *ctx, char *err, int exit_code)
{
	perror(err);
	free_pipex(ctx);
	exit(exit_code);
}
