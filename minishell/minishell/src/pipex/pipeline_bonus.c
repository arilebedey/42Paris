/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:11:03 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:28:12 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	pipeline(t_pipex *ctx, char **av, char **env)
{
	int	i;
	int	offset;

	if (ctx->here_doc)
		offset = 3;
	else
		offset = 2;
	i = 0;
	while (i < ctx->cmd_count)
	{
		ctx->pids[i] = fork();
		if (ctx->pids[i] == 0)
			exec_cmd(ctx, av[i + offset], env, i);
		else if (ctx->pids[i] == -1)
		{
			close_forks(ctx, i);
			close_pipes(ctx, 0);
			print_perror_exit(ctx, "C fork() failed");
		}
		i++;
	}
	close_pipes(ctx, 0);
}
