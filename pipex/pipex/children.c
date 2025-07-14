/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 03:50:02 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/14 18:16:50 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

static void	close_unused_pipes(t_pipex *ctx, int cmd_index)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count - 1)
	{
		if (i != cmd_index - 1)
			close(ctx->pipes[i][0]);
		if (i != cmd_index)
			close(ctx->pipes[i][1]);
		i++;
	}
}

static void	setup_input(t_pipex *ctx, int cmd_index)
{
	if (cmd_index == 0)
	{
		if (ctx->here_doc)
		{
			if (dup2(ctx->here_pipe[0], 0) < 0)
				print_sys_error_exit(ctx, "dup2 here_doc");
			close(ctx->here_pipe[0]);
			ctx->here_pipe[0] = -1;
		}
		else
		{
			if (dup2(ctx->infile, 0) < 0)
				print_sys_error_exit(ctx, "dup2 infile");
			if (ctx->infile >= 0)
				close(ctx->infile);
		}
	}
	else
	{
		if (dup2(ctx->pipes[cmd_index - 1][0], 0) < 0)
			print_sys_error_exit(ctx, "dup2 pipe read");
		close(ctx->pipes[cmd_index - 1][0]);
	}
}

static void	setup_output(t_pipex *ctx, int cmd_index)
{
	if (cmd_index == ctx->cmd_count - 1)
	{
		if (dup2(ctx->outfile, 1) < 0)
			print_sys_error_exit(ctx, "dup2 outfile");
		close(ctx->outfile);
	}
	else
	{
		if (dup2(ctx->pipes[cmd_index][1], 1) < 0)
			print_sys_error_exit(ctx, "dup2 pipe write");
		close(ctx->pipes[cmd_index][1]);
	}
}

void	setup_child_pipes(t_pipex *ctx, int cmd_index)
{
	close_unused_pipes(ctx, cmd_index);
	setup_input(ctx, cmd_index);
	setup_output(ctx, cmd_index);
}

int	wait_for_children(t_pipex *ctx)
{
	int	i;
	int	status;
	int	last_status;

	i = 0;
	while (i < ctx->cmd_count)
	{
		waitpid(ctx->pids[i], &status, 0);
		if (i == ctx->cmd_count - 1 && WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		i++;
	}
	return (last_status);
}
