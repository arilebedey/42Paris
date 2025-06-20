/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/20 17:55:49 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	ctx;

	if (ac != 5)
		return (print_error(ERR_INPUT));
	ctx.infile = open(av[1], O_RDONLY);
	if (ctx.infile < 0)
		perror_exit(ERR_INFILE);
	ctx.outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (ctx.outfile < 0)
		perror_exit(ERR_OUTFILE);
	if (pipe(ctx.pipefd) < 0)
		perror_exit(ERR_PIPE);
	ctx.paths = find_path(env);
	if (!ctx.paths)
		perror_exit(ERR_PATH);
	ctx.pid1 = fork();
	if (ctx.pid1 == 0)
		first_child(ctx, av, env);
	ctx.pid2 = fork();
	if (ctx.pid2 == 0)
		second_child(ctx, av, env);
	close_pipes(&ctx);
	waitpid(ctx.pid1, NULL, 0);
	waitpid(ctx.pid2, NULL, 0);
	return (free_parent(&ctx));
}
