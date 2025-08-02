/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:38:41 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/02 20:40:17 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	update_animation(t_game *game)
{
	static int	counter = 0;

	counter++;
	if (counter >= 4000)
	{
		game->current_frame++;
		if (game->current_frame >= game->collectible_frame)
			game->current_frame = 0;
		render_map(game);
		counter = 0;
	}
	return (0);
}
