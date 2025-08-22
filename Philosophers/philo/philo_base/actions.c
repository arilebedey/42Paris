/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:12:54 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/22 21:39:39 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pick_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(first);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(second);
	print_state(philo, "has taken a fork");
}

static void	put_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	else
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	pthread_mutex_unlock(first);
	pthread_mutex_unlock(second);
}

void	action_eat(t_philo *philo)
{
	if (philo->sim->count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
		msleep(philo->sim->time_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pick_forks(philo);
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->sim->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	msleep(philo->sim->time_eat);
	put_forks(philo);
}

void	action_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping");
	msleep(philo->sim->time_sleep);
}

void	action_think(t_philo *philo)
{
	size_t	think_ms;

	pthread_mutex_lock(&philo->sim->meal_lock);
	think_ms = (philo->sim->time_die - (get_time() - philo->last_meal)
			- philo->sim->time_eat) / 2;
	pthread_mutex_unlock(&philo->sim->meal_lock);
	if ((long)think_ms < 0)
		think_ms = 0;
	if (think_ms > 600)
		think_ms = 200;
	print_state(philo, "is thinking");
	if (think_ms)
		msleep(think_ms);
}
