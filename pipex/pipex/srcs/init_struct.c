/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:13:34 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/13 02:05:56 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	init_pids(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count)
	{
		ctx->pids[i] = -1;
		i++;
	}
}

static void	init_pipes(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count - 1)
	{
		ctx->pipes[i] = malloc(sizeof(int) * 2);
		if (!ctx->pipes[i])
			print_sys_error_exit(ctx, ERR_MALLOC);
		ctx->pipes[i][0] = -1;
		ctx->pipes[i][1] = -1;
		i++;
	}
}

static void	init_cmds(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count)
	{
		ctx->cmds[i] = NULL;
		i++;
	}
}

/*
 * Initializes the pipex structure and allocates all required resources.
 * Exits gracefully if any allocation fails.
 */
void	init_struct(t_pipex *ctx, int cmd_count)
{
	ctx->cmd_count = cmd_count;
	ctx->pids = malloc(sizeof(pid_t) * cmd_count);
	if (!ctx->pids)
		print_sys_error_exit(ctx, ERR_MALLOC);
	ctx->pipes = malloc(sizeof(int *) * (cmd_count - 1));
	if (!ctx->pipes)
		print_sys_error_exit(ctx, ERR_MALLOC);
	ctx->cmds = malloc(sizeof(char **) * cmd_count);
	if (!ctx->cmds)
		print_sys_error_exit(ctx, ERR_MALLOC);
	ctx->infile = -1;
	ctx->outfile = -1;
	ctx->paths = NULL;
	init_pids(ctx);
	init_pipes(ctx);
	init_cmds(ctx);
}
