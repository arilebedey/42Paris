/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:38:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/21 22:10:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

int	update_animation(t_game *game)
{
	static int	counter = 0;
	static int	counter_enemy = 0;
	static int	enemy = 0;

	counter++;
	counter_enemy++;
	if (counter >= 20000)
	{
		game->current_frame++;
		if (game->current_frame >= game->collectible_frame)
			game->current_frame = 0;
		render_map(game);
		counter = 0;
	}
	if (counter_enemy >= 20000)
	{
		if (game->enemy_is_alive)
			move_enemy(game, &enemy);
		counter_enemy = 0;
	}
	return (0);
}
