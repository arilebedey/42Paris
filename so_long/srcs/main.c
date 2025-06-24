/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:32:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/06/24 16:26:50 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	arg_error(argc, argv[1]);
	game.map = read_file(argv[1]);
	return (EXIT_SUCCESS);
}
