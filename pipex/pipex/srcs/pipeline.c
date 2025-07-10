/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:11:03 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/13 01:59:15 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_pipeline(t_pipex *ctx, char **av, char **env)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count)
	{
		ctx->pids[i] = fork();
		if (ctx->pids[i] == 0)
			exec_command(ctx, av[i + 2], env, i);
		else if (ctx->pids[i] == -1)
		{
			close_forks(ctx, i);
			close_pipes(ctx, 0);
			print_sys_error_exit(ctx, "C fork() failed");
		}
	}
	close_pipes(ctx, 0);
}
