/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:43:55 by lengarci          #+#    #+#             */
/*   Updated: 2025/01/26 17:51:15 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void	init_arr(int *arr)
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
}

void	next_permutation(int *arr, int n, int *count)
{
	int	i;
	int	j;

	if (arr[0] == 0)
	{
		init_arr(arr);
		return ;
	}
	i = n - 2;
	while (i >= 0 && arr[i] >= arr[i + 1])
		i--;
	if (i < 0)
	{
		reverse(arr, 0, n - 1);
		*count = *count + 1;
		return ;
	}
	j = n - 1;
	while (arr[j] <= arr[i])
		j--;
	swap(&arr[i], &arr[j]);
	reverse(arr, i + 1, n - 1);
	*count = *count + 1;
}
/*
int	main()
{
	int	tab [] = {1, 2, 3, 4};
	int	n = 4;
	int	i = 0;

	next_permutation(tab, n);
	while (tab[i + 1])
	{
		printf("%d\n", tab[i]);
		i++;
	}
	next_permutation(tab, n);
	i = 0;
	while (tab[i + 1])
	{
		printf("%d\n", tab[i]);
		i++;
	}
}*/
