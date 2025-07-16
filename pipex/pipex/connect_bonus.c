/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:41:32 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:26:51 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

static void	handle_here_doc(t_pipex *ctx, char *limiter)
{
	char	*line;

	if (pipe(ctx->here_pipe) == -1)
		print_perror_exit(ctx, ERR_PIPE);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(ctx->here_pipe[1], line, ft_strlen(line));
		free(line);
	}
	close(ctx->here_pipe[1]);
	ctx->here_pipe[1] = -1;
	ctx->infile = ctx->here_pipe[0];
}

void	get_pipes(t_pipex *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->cmd_count - 1)
	{
		if (pipe(ctx->pipes[i]) == -1)
		{
			close_pipes(ctx, i);
			print_perror_exit(ctx, ERR_PIPE);
		}
		i++;
	}
}

void	get_file_fds(t_pipex *ctx, char **av, int ac)
{
	if (ctx->here_doc)
		handle_here_doc(ctx, ctx->limiter);
	else
	{
		ctx->infile = open(av[1], O_RDONLY);
		if (ctx->infile < 0)
		{
			perror(av[1]);
			ctx->infile = open("/dev/null", O_RDONLY);
		}
	}
	if (ctx->here_doc)
		ctx->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		ctx->outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (ctx->outfile < 0)
		print_perror_exit(ctx, ERR_OUTFILE);
}

void	get_paths(t_pipex *ctx, char **env)
{
	ctx->paths = find_path(env);
	if (!ctx->paths)
		print_perror_exit(ctx, ERR_PATH);
}
