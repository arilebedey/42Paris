/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 05:36:29 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:27:18 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	exec_cmd(t_pipex *ctx, char *cmd_str, char **env, int cmd_index)
{
	char	**cmd;

	setup_child_pipes(ctx, cmd_index);
	cmd = get_cmd(ctx->paths, cmd_str);
	if (!cmd)
		print_error_exit_code(ctx, ERR_CMD, 127);
	execve(cmd[0], cmd, env);
	print_perror_exit_code(ctx, ERR_EXECVE, 126);
}
