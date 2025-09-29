/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:52:55 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/29 10:14:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	print_state(t_philo *philo, char *msg)
{
	t_sim	*sim;
	size_t	time_elapsed;
	int		done;

	sim = philo->sim;
	pthread_mutex_lock(&sim->death_lock);
	done = sim->finished;
	pthread_mutex_unlock(&sim->death_lock);
	if (!done)
	{
		pthread_mutex_lock(&sim->write_lock);
		time_elapsed = get_time() - sim->start_time;
		printf("%zu %d %s\n", time_elapsed, philo->id, msg);
		pthread_mutex_unlock(&sim->write_lock);
	}
}
