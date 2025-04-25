/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:27:59 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/18 14:28:27 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	rush(int x, int y);

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc < 3)
		return ;
	(void) argc;
	x = atoi(argv[1]);
	y = atoi(argv[2]);
	rush(x, y);
	return (0);
}
