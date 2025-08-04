/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:53:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:27:29 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	close_pipes(t_pipex *ctx)
{
	close(ctx->pipefd[0]);
	close(ctx->pipefd[1]);
}

void	free_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

int	free_parent(t_pipex *ctx)
{
	int	i;

	if (ctx->infile >= 0)
		close(ctx->infile);
	if (ctx->outfile >= 0)
		close(ctx->outfile);
	if (ctx->pipefd[0] >= 0)
		close(ctx->pipefd[0]);
	if (ctx->pipefd[1] >= 0)
		close(ctx->pipefd[1]);
	if (ctx->cmd)
		free_child(ctx);
	if (ctx->paths)
	{
		i = 0;
		while (ctx->paths[i])
			free(ctx->paths[i++]);
		free(ctx->paths);
		ctx->paths = NULL;
	}
	return (0);
}

void	free_child(t_pipex *ctx)
{
	int	i;

	if (!ctx->cmd)
		return ;
	i = 0;
	while (ctx->cmd[i])
		free(ctx->cmd[i++]);
	free(ctx->cmd);
	ctx->cmd = NULL;
}
