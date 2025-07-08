/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:21:14 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/08 22:39:19 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	on_hit_enemy(t_game *game)
{
	destroy_game(game);
	ft_putstr_fd("You touched an enemy\n", 2);
}
