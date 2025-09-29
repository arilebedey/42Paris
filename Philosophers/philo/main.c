/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:38:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/21 20:48:38 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (parse_args(argc, argv, &sim))
		return (EXIT_FAILURE);
	if (create_structs(&sim))
		return (EXIT_FAILURE);
	if (init_mutexes(&sim))
		return (EXIT_FAILURE);
	init_philos(&sim);
	launch_sim(&sim);
	clean_sim(&sim);
	return (0);
}
