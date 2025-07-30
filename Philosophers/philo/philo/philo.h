/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:38:15 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/30 21:56:19 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo	t_philo;
typedef struct s_sim	t_sim;

struct					s_philo
{
	int					id;
	pthread_t			thread;
	size_t				last_meal;
	int					meals_eaten;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_sim				*sim;
};

struct					s_sim
{
	int					count;
	int					must_eat;
	size_t				time_die;
	size_t				time_eat;
	size_t				time_sleep;
	size_t				start_time;
	int					someone_dead;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		death_lock;
};

// utils
int						ft_atoi(char *str);
size_t					ft_strlen(const char *s);

// error.c
int						print_error(char *err);

// exit.c
void					free_dynamics(t_sim *sim);
void					free_at_mutex_init(t_sim *sim, int stage);
void					free_at_mutex_forks(t_sim *sim, int i);

// init.c
int						parse_args(int ac, char **av, t_sim *sim);
int						create_structs(t_sim *sim);
int						init_mutexes(t_sim *sim);
void					init_philos(t_sim *sim);

#endif
