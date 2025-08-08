/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 23:39:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/08 19:14:30 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

char	**find_path(char **env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env)
		return (NULL);
	return (ft_split(*env + 5, ':'));
}

void	parse_args(t_pipex *ctx, int ac, char **av)
{
	if (ac < 5)
	{
		print_error(ERR_FEW_ARGS);
		exit(1);
	}
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
