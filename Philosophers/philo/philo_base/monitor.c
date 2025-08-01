/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:04:02 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/01 22:22:29 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_sim *sim)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < sim->count)
	{
		philo = &sim->philos[i];
		pthread_mutex_lock(&sim->meal_lock);
		if (get_time() - philo->last_meal >= sim->time_die && !sim->finished)
		{
			pthread_mutex_unlock(&sim->meal_lock);
			pthread_mutex_lock(&sim->death_lock);
			sim->finished = 1;
			pthread_mutex_unlock(&sim->death_lock);
			pthread_mutex_lock(&sim->write_lock);
			printf("%zu %d died\n", get_time() - sim->start_time, philo->id);
			pthread_mutex_unlock(&sim->write_lock);
			return (1);
		}
		pthread_mutex_unlock(&sim->meal_lock);
		i++;
	}
	return (0);
}

static int	check_full(t_sim *sim)
{
	int	count;
	int	i;

	if (sim->must_eat == -1)
		return (0);
	count = 0;
	i = 0;
	while (i < sim->count)
	{
		pthread_mutex_lock(&sim->meal_lock);
		if (sim->philos[i].meals_eaten >= sim->must_eat)
			count++;
		pthread_mutex_unlock(&sim->meal_lock);
		i++;
	}
	if (count == sim->count)
	{
		pthread_mutex_lock(&sim->death_lock);
		sim->finished = 1;
		pthread_mutex_unlock(&sim->death_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *pthread_arg)
{
	t_sim	*sim;

	sim = pthread_arg;
	while (1)
	{
		if (check_death(sim) || check_full(sim))
			break ;
		usleep(1000);
	}
	return (NULL);
}
