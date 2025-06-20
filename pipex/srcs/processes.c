/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:36:21 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/20 17:55:59 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex ctx, char *av[], char *env[])
{
	close(ctx.pipefd[0]);
	dup2(ctx.pipefd[1], 1);
	close(ctx.pipefd[1]);
	dup2(ctx.infile, 0);
	close(ctx.infile);
	ctx.cmd = get_cmd(ctx.paths, av[2]);
	if (!ctx.cmd)
	{
		free_child(&ctx);
		free_paths(ctx.paths);
		print_error(ERR_CMD);
		exit(1);
	}
	execve(ctx.cmd[0], ctx.cmd, env);
	perror_exit(ERR_EXECVE);
}

void	second_child(t_pipex ctx, char *av[], char *env[])
{
	close(ctx.pipefd[1]);
	dup2(ctx.pipefd[0], 0);
	close(ctx.pipefd[0]);
	dup2(ctx.outfile, 1);
	close(ctx.outfile);
	ctx.cmd = get_cmd(ctx.paths, av[3]);
	if (!ctx.cmd)
	{
		free_child(&ctx);
		free_paths(ctx.paths);
		print_error(ERR_CMD);
		exit(1);
	}
	execve(ctx.cmd[0], ctx.cmd, env);
	perror_exit(ERR_EXECVE);
}
