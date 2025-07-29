/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:38:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/29 21:26:00 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	sim;

	if (parse_args(argc, argv, &sim))
		return (1);
	launch_sim(&sim);
	clean_sim(&sim);
	return (0);
}
