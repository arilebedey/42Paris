/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 22:03:30 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/08 21:44:31 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*line;
	t_token	*tokens;
	t_ms	ms;
	pid_t	pid;
	int		status;

	(void)argc;
	(void)argv;
	ms.env = env;
	line = readline("$ ");
	while (line)
	{
		if (*line)
			add_history(line);
		tokens = lexer(line);
		free(line);
		if (!tokens)
			continue ;
		ms.ast = build_ast(tokens);
		if (!ms.ast)
			continue ;
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			free_ast(ms.ast);
			break ;
		}
		if (pid == 0)
		{
			exec_ast(&ms, ms.ast);
			exit(1);
		}
		waitpid(pid, &status, 0);
		free_ast(ms.ast);
		line = readline("$ ");
	}
	return (0);
}
