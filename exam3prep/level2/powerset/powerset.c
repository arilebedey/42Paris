/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 07:42:48 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/22 11:37:48 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_subset(int *subset, int size)
{
	if (size == 0)
	{
		printf("\n");
		return ;
	}
	for (int i = 0; i < size; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subset[i]);
	}
	printf("\n");
}

// backtrack(arr, subset, n, 0, 0, target, 0);
void	backtrack(int *arr, int *subset, int n, int sum, int idx, int target,
		int size)
{
	if (idx == n)
	{
		if (sum == target)
		{
			print_subset(subset, size);
		}
		return ;
	}
	backtrack(arr, subset, n, sum, idx + 1, target, size);
	subset[size] = arr[idx];
	backtrack(arr, subset, n, sum + arr[idx], idx + 1, target, size + 1);
}

int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
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
	n = ac - 2;
	target = atoi(av[1]);
	subset = malloc(sizeof(int) * n);
	arr = malloc(sizeof(int) * n);
	if (!subset || !arr)
		return (1);
	for (int i = 0; i < n; i++)
	{
		if (!is_valid(av[i + 2]))
			return (1);
		arr[i] = atoi(av[i + 2]);
	}
	backtrack(arr, subset, n, 0, 0, target, 0);
	free(arr);
	free(subset);
	return (0);
}
