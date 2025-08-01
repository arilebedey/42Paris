/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:14:52 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/01 21:55:27 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *pthread_arg)
{
	t_philo	*philo;
	int		dead;

	philo = pthread_arg;
	if (philo->id % 2 == 0)
		msleep(1);
	while (1)
	{
		pthread_mutex_lock(&philo->sim->death_lock);
		dead = philo->sim->finished;
		pthread_mutex_unlock(&philo->sim->death_lock);
		if (dead)
			break ;
		action_eat(philo);
		action_sleep(philo);
		action_think(philo);
	}
	return (NULL);
}

int	launch_sim(t_sim *sim)
{
	pthread_t	monitor;
	int			i;

	pthread_create(&monitor, NULL, monitor_routine, sim);
	i = sim->count;
	while (i-- > 0)
		pthread_create(&sim->philos[i].thread, NULL, philo_routine,
			&sim->philos[i]);
	pthread_join(monitor, NULL);
	i = sim->count;
	while (i-- > 0)
		pthread_join(sim->philos[i].thread, NULL);
	return (0);
}
