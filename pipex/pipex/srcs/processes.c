/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:36:21 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/23 17:25:45 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex ctx, char *av[], char *env[])
{
	close(ctx.pipefd[0]);
	if (dup2(ctx.pipefd[1], 1) < 0)
	{
		free_paths(ctx.paths);
		perror_exit("dup2 pipefd[1]");
	}
	close(ctx.pipefd[1]);
	if (dup2(ctx.infile, 0) < 0)
	{
		free_paths(ctx.paths);
		perror_exit("dup2 infile");
	}
	close(ctx.infile);
	ctx.cmd = get_cmd(ctx.paths, av[2]);
	if (!ctx.cmd)
	{
		free_child(&ctx);
		free_paths(ctx.paths);
		print_error(ERR_CMD);
		exit(127);
	}
	execve(ctx.cmd[0], ctx.cmd, env);
	perror_exit(ERR_EXECVE);
}

void	second_child(t_pipex ctx, char *av[], char *env[])
{
	close(ctx.pipefd[1]);
	if (dup2(ctx.pipefd[0], 0) < 0)
	{
		free_paths(ctx.paths);
		perror_exit("dup2 pipefd[0]");
	}
	if (dup2(ctx.outfile, 1) < 0)
	{
		free_paths(ctx.paths);
		perror_exit("dup2 outfile");
	}
	close(ctx.outfile);
	ctx.cmd = get_cmd(ctx.paths, av[3]);
	if (!ctx.cmd)
	{
		free_child(&ctx);
		free_paths(ctx.paths);
		print_error(ERR_CMD);
		exit(127);
	}
	execve(ctx.cmd[0], ctx.cmd, env);
	perror_exit(ERR_EXECVE);
}
