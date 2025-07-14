/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:03:08 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/14 18:15:26 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

static void	free_cmd_args(char **cmd_args)
{
	int	i;

	if (!cmd_args)
		return ;
	i = 0;
	while (cmd_args[i])
		free(cmd_args[i++]);
	free(cmd_args);
}

static char	**split_cmd_args(char *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		return (NULL);
	if (!cmd_args[0])
	{
		free(cmd_args);
		return (NULL);
	}
	return (cmd_args);
}

char	**find_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env)
		return (NULL);
	return (ft_split(*env + 5, ':'));
}

char	**get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**cmd_args;

	cmd_args = split_cmd_args(cmd);
	if (!cmd_args)
		return (NULL);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd_args[0]);
		free(tmp);
		if (access(command, F_OK) == 0)
		{
			free(cmd_args[0]);
			cmd_args[0] = command;
			return (cmd_args);
		}
		free(command);
		paths++;
	}
	free_cmd_args(cmd_args);
	return (NULL);
}

void	parse_args(t_pipex *ctx, int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		ctx->here_doc = 1;
		ctx->limiter = av[2];
		init_struct(ctx, ac - 4);
	}
	else
	{
		ctx->here_doc = 0;
		ctx->limiter = NULL;
		init_struct(ctx, ac - 3);
	}
}
