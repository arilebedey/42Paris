/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:03:08 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:28:08 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

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

static char	**get_cmd_with_slash(char *cmd)
{
	char	**cmd_args;

	cmd_args = malloc(sizeof(char *) * 2);
	if (!cmd_args)
		return (NULL);
	cmd_args[0] = ft_strdup(cmd);
	cmd_args[1] = NULL;
	if (access(cmd_args[0], F_OK | X_OK) == 0)
		return (cmd_args);
	free_cmd_args(cmd_args);
	return (NULL);
}

char	**get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**cmd_args;

	if (ft_strchr(cmd, '/'))
		return (get_cmd_with_slash(cmd));
	cmd_args = split_cmd_args(cmd);
	if (!cmd_args)
		return (NULL);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd_args[0]);
		free(tmp);
		if (access(command, X_OK) == 0)
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
