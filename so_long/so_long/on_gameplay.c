/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:21:14 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/18 20:42:59 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "libft/libft.h"

void	record_new_move(t_game *game)
{
	char	*moves;

	game->moves_count = game->moves_count + 1;
	moves = ft_itoa(game->moves_count);
	ft_putstr_fd("New movement count: ", 1);
	ft_putstr_fd(moves, 1);
	ft_putstr_fd("\n", 1);
}

void	on_hit_enemy(t_game *game)
{
	ft_putstr_fd("You touched an enemy\n", 1);
	destroy_game(game);
}

void	on_hit_collectible(t_game *game, int new_y, int new_x)
{
	game->map[new_y][new_x] = '0';
	if (--game->collectible_count == 0)
		open_game_exit(game->map);
}

void	on_game_complete(t_game *game)
{
	record_new_move(game);
	ft_putstr_fd("Game finished!\n", 1);
	destroy_game(game);
	exit(0);
}
