/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:16:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/16 20:27:53 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	ctx;
	int		exit_status;

	parse_args(&ctx, ac, av);
	get_file_fds(&ctx, av, ac);
	get_paths(&ctx, env);
	get_pipes(&ctx);
	pipeline(&ctx, av, env);
	exit_status = wait_for_children(&ctx);
	close_pipes(&ctx, 0);
	free_pipex(&ctx);
	return (exit_status);
}
