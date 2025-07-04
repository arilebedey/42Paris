/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:31:01 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/04 23:33:40 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	mlx_init_error(t_game *game)
{
	if (game->map)
		free_map(game->map);
	ft_putstr_fd("Error\nMinilibX couldn't init\n", 2);
	exit(1);
}

void	img_load_error(t_game *game)
{
	if (game->map)
		free_map(game->map);
	ft_putstr_fd("Error\nCouldn't load images\n", 2);
	exit(1);
}
