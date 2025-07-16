/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:27:43 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	init_pipex(t_pipex *ctx)
{
	ctx->pid1 = -1;
	ctx->pid2 = -1;
	ctx->pipefd[0] = -1;
	ctx->pipefd[1] = -1;
	ctx->infile = -1;
	ctx->outfile = -1;
	ctx->paths = NULL;
	ctx->cmd = NULL;
}

int	setup_pipex(int ac, char **av, char **env, t_pipex *ctx)
{
	if (ac != 5)
		return (print_error(ERR_INPUT));
	init_pipex(ctx);
	ctx->infile = open(av[1], O_RDONLY);
	if (ctx->infile < 0)
		print_warn(ERR_INFILE);
	ctx->outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (ctx->outfile < 0)
		perror_exit(ERR_OUTFILE);
	if (pipe(ctx->pipefd) < 0)
		perror_exit(ERR_PIPE);
	ctx->paths = find_path(env);
	if (!ctx->paths)
		perror_exit(ERR_PATH);
	return (0);
}

void	run_children(t_pipex *ctx, char **av, char **env)
{
	ctx->pid1 = fork();
	if (ctx->pid1 == 0)
		first_child(*ctx, av, env);
	ctx->pid2 = fork();
	if (ctx->pid2 == 0)
		second_child(*ctx, av, env);
}

int	cleanup_and_wait(t_pipex *ctx)
{
	int	status1;
	int	status2;

	close_pipes(ctx);
	waitpid(ctx->pid1, &status1, 0);
	waitpid(ctx->pid2, &status2, 0);
	free_parent(ctx);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	ctx;

	if (setup_pipex(ac, av, env, &ctx))
		return (1);
	run_children(&ctx, av, env);
	return (cleanup_and_wait(&ctx));
}
