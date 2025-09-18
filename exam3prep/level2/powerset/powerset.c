/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:42:48 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/16 09:04:43 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_subset(int *subset, int size)
{
	char	buf[32];
	int		l;

	if (size == 0)
	{
		write(1, "\n", 1);
		return ;
	}
	for (int i = 0; i < size; i++)
	{
		if (i > 0)
			write(1, " ", 1);
		l = sprintf(buf, "%d", subset[i]);
		write(1, buf, l);
	}
	write(1, "\n", 1);
}

void	backtrack(int *arr, int n, int target, int idx, int sum, int *subset,
		int size)
{
	if (idx == n)
	{
		if (sum == target)
			print_subset(subset, size);
		return ;
	}
	// skip element
	backtrack(arr, n, target, idx + 1, sum, subset, size);
	// include element
	subset[size] = arr[idx];
	backtrack(arr, n, target, idx + 1, sum + arr[idx], subset, size + 1);
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	target;
	int	n;
	int	*arr;
	int	*subset;

	if (ac < 2)
		return (1);
	target = atoi(av[1]);
	n = ac - 2;
	arr = malloc(sizeof(int) * n);
	subset = malloc(sizeof(int) * n);
	if (!arr || !subset)
		return (1);
	for (int i = 0; i < n; i++)
	{
		if (!is_valid(av[i + 2]))
			return (1);
		arr[i] = atoi(av[i + 2]);
	}
	backtrack(arr, n, target, 0, 0, subset, 0);
	free(arr);
	free(subset);
	return (0);
}
