/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:30:56 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/30 21:57:08 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int ac, char **av, t_sim *sim)
{
	if (ac != 5 && ac != 6)
		return (print_error("Wrong args\n"));
	sim->count = ft_atoi(av[1]);
	sim->time_die = ft_atoi(av[2]);
	sim->time_eat = ft_atoi(av[3]);
	sim->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		sim->must_eat = ft_atoi(av[5]);
	else
		sim->must_eat = -1;
	if (sim->count <= 0 || sim->time_sleep <= 0 || sim->time_die <= 0
		|| sim->time_eat <= 0 || (ac == 6 && sim->must_eat < 0))
		return (print_error("Invalid args\n"));
	return (EXIT_SUCCESS);
}

int	create_structs(t_sim *sim)
{
	sim->philos = malloc(sizeof(t_philo) * sim->count);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->count);
	if (!sim->philos || !sim->forks)
		return (free_dynamics(sim), EXIT_FAILURE);
	sim->someone_dead = 0;
	sim->start_time = get_time();
	return (EXIT_SUCCESS);
}

int	init_mutexes(t_sim *sim)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&sim->write_lock, NULL))
		return (free, EXIT_FAILURE);
	if (pthread_mutex_init(&sim->meal_lock, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&sim->death_lock, NULL))
		return (EXIT_FAILURE);
	while (i < sim->count)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	init_philos(t_sim *sim)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < sim->count)
	{
		philo = &sim->philos[i];
		philo->id = i + 1;
		philo->last_meal = sim->start_time;
		philo->meals_eaten = 0;
		philo->left_fork = &sim->forks[i];
		philo->right_fork = &sim->forks[(i + 1) % sim->count];
		philo->sim = sim;
		i++;
	}
}
