/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:31:43 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/11 22:35:39 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_forks(t_pipex *ctx, int i)
{
	int	j;

	j = 0;
	while (j < i)
		waitpid(ctx->pids[j], NULL, 0);
}

void	close_pipes(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count - 1)
	{
		close(ctx->pipes[i][0]);
		close(ctx->pipes[i][1]);
		i++;
	}
	if (ctx->infile > -1)
		close(ctx->infile);
	close(ctx->outfile);
}
