/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:31:43 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/13 01:58:52 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_forks(t_pipex *ctx, int i)
{
	int	j;

	j = 0;
	while (j < i)
		waitpid(ctx->pids[j++], NULL, 0);
}

/**
 * @brief Closes and frees up to i pipes.
 *        If i == 0, closes all pipes.
 */
void	close_pipes(t_pipex *ctx, int i)
{
	int	j;

	if (i == 0)
		i = ctx->cmd_count - 1;
	j = 0;
	while (j < i)
	{
		close(ctx->pipes[j][0]);
		close(ctx->pipes[j][1]);
		free(ctx->pipes[j]);
		j++;
	}
	if (ctx->infile > -1)
		close(ctx->infile);
	close(ctx->outfile);
}
