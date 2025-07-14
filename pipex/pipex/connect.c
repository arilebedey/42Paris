/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:41:32 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/13 02:44:41 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	get_pipes(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count - 1)
	{
		if (pipe(ctx->pipes[i]) == -1)
		{
			close_pipes(ctx, i);
			print_sys_error_exit(ctx, ERR_PIPE);
		}
		i++;
	}
}

void	get_file_fds(t_pipex *ctx, char **av, int ac)
{
	ctx->infile = open(av[1], O_RDONLY);
	if (ctx->infile < 0)
		print_warn(ERR_INFILE);
	ctx->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (ctx->outfile < 0)
		print_sys_error_exit(ctx, ERR_OUTFILE);
}

void	get_paths(t_pipex *ctx, char **env)
{
	ctx->paths = find_path(env);
	if (!ctx->paths)
		print_sys_error_exit(ctx, ERR_PATH);
}
