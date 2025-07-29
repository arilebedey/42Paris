/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:30:56 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/29 21:54:25 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(int argc, char **argv, t_sim *sim)
{
	if (argc != 5 && argc != 6)
		return (write(2, "Wrong args\n", 11), 1);
	sim->count = ft_atoi(argv[1]);
	sim->time_die = ft_atoi(argv[2]);
	sim->time_eat = ft_atoi(argv[3]);
	sim->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		sim->must_eat = ft_atoi(argv[5]);
	else
		sim->must_eat = -1;
}
