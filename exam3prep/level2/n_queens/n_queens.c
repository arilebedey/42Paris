/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 10:51:48 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/22 08:16:08 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	write_solutions(int nb)
{
	char	c;

	if (nb >= 10)
		write_solutions(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	write_solutions_recursive(int *positions, int n, int index)
{
	if (index == n)
	{
		write(1, "\n", 1);
		return ;
	}
	write_solutions(positions[index]);
	if (index < n - 1)
		write(1, " ", 1);
	write_solutions_recursive(positions, n, index + 1);
}

int	is_valid_positions(int *positions, int row, int col)
{
	int	c;
	int	r;

	c = 0;
	while (c < col)
	{
		r = positions[c];
		if (c - r == col - row)
			return (0);
		if (c - row == col - r)
			return (0);
		if (r == row)
			return (0);
		c++;
	}
	return (1);
}

void	find_solutions(int *positions, int n, int col)
{
	int	row;

	row = 0;
	if (col == n)
	{
		write_solutions_recursive(positions, n, 0);
		return ;
	}
	while (row < n)
	{
		if (is_valid_positions(positions, row, col))
		{
			positions[col] = row;
			find_solutions(positions, n, col + 1);
		}
		row++;
	}
}

int	main(int ac, char *av[])
{
	int	n;
	int	positions[n];

	if (ac != 2)
		return (1);
	n = atoi(av[1]);
	if (n <= 0)
		return (1);
	find_solutions(positions, n, 0);
	return (0);
}
