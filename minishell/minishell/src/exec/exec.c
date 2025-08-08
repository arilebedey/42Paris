/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:01:11 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/08 21:44:57 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	run_execve(t_ms *ms, char *cmd)
{
	char	**argv;
	char	**paths;

	paths = find_path(ms->env);
	if (!paths)
	{
		ft_putstr_fd("PATH not set\n", 2);
		exit(127);
	}
	argv = get_cmd(paths, cmd);
	free_tab(paths);
	if (!argv)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd, 2);
		exit(127);
	}
	execve(argv[0], argv, ms->env);
	perror("execve");
	exit(EXIT_FAILURE);
}

static void	exec_cmd(t_ms *ms, t_tree *node)
{
	run_execve(ms, node->tok->text);
}

static void	exec_redir_out(t_ms *ms, t_tree *root)
{
	int	fd;

	fd = open(root->right->tok->text, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
	exec_ast(ms, root->left);
	exit(EXIT_FAILURE);
}

static void	exec_pipe(t_ms *ms, t_tree *root)
{
	int		fds[2];
	pid_t	left_child;
	pid_t	right_child;

	if (pipe(fds) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	left_child = fork();
	if (left_child < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (left_child == 0)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		close(fds[1]);
		exec_ast(ms, root->left);
		exit(EXIT_FAILURE);
	}
	right_child = fork();
	if (right_child < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (right_child == 0)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		close(fds[1]);
		exec_ast(ms, root->right);
		exit(EXIT_FAILURE);
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(left_child, NULL, 0);
	waitpid(right_child, NULL, 0);
}

int	exec_ast(t_ms *ms, t_tree *root)
{
	if (!root || !root->tok)
		return (0);
	if (root->tok->type == T_WORD)
		exec_cmd(ms, root);
	else if (root->tok->type == T_REDIR_OUT)
		exec_redir_out(ms, root);
	else if (root->tok->type == T_PIPE)
		exec_pipe(ms, root);
	return (0);
}
