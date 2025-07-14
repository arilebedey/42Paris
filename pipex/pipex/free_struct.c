/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:53:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/14 07:47:23 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_pipes(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count - 1)
	{
		if (ctx->pipes[i])
			free(ctx->pipes[i]);
		i++;
	}
	free(ctx->pipes);
}

static void	free_cmds(t_pipex *ctx)
{
	int	i;
	int	j;

	i = 0;
	while (i < ctx->cmd_count)
	{
		if (ctx->cmds[i])
		{
			j = 0;
			while (ctx->cmds[i][j])
				free(ctx->cmds[i][j++]);
			free(ctx->cmds[i]);
		}
		i++;
	}
	free(ctx->cmds);
}

static void	free_paths(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (ctx->paths[i])
		free(ctx->paths[i++]);
	free(ctx->paths);
}

void	free_pipex(t_pipex *ctx)
{
	if (ctx->pids)
		free(ctx->pids);
	if (ctx->pipes)
		free_pipes(ctx);
	if (ctx->cmds)
		free_cmds(ctx);
	if (ctx->paths)
		free_paths(ctx);
}
