/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:31:36 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/30 21:56:12 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_dynamics(t_sim *sim)
{
	if (sim->forks)
		free(sim->forks);
	if (sim->philos)
		free(sim->philos);
}

void	free_at_mutex_init(t_sim *sim, int stage)
{
	int	i;

	if (stage >= 1)
		pthread_mutex_destroy(&sim->write_lock);
	if (stage >= 2)
		pthread_mutex_destroy(&sim->meal_lock);
	if (stage >= 3)
		pthread_mutex_destroy(&sim->death_lock);
	free_dynamics(sim);
}

void	free_at_mutex_forks(t_sim *sim, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i--;
	}
	free_at_mutex_init(sim, 3);
}
