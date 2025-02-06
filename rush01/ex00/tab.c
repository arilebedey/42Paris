/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:12:38 by lengarci          #+#    #+#             */
/*   Updated: 2025/01/26 22:00:46 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

int	**create_tab(int n)
{
	int	**tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int *) * n + 1);
	i = 0;
	while (i < n)
	{
		tab[i] = malloc(sizeof(int) * n);
		i++;
	}
	tab[i] = malloc(sizeof(int));

	// Populate with 0
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int	unique_col(int **tab, int col, int n)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < n)
	{
		j = i;
		count = 0;
		while (j < n)
		{
			if (tab[i][col] == tab[j][col])
			{
				count++;
				if (count == 2)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	unique_row(int **tab, int row, int n)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < n)
	{
		j = i;
		count = 0;
		while (j < n)
		{
			if (tab[row][i] == tab[row][j])
			{
				count++;
				if (count == 2)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	test_row(int **tab, int row, int viewl, int viewr)
{
	/*
	printf("\n");
	int j = 0;
	while (j < 4)
	{
		for (int i = 0; i < 4; i++)
			printf("%i\t", tab[j][i]);
		printf("\n");
		j++;
	}
	printf("verif left view. result: %i\tviewl: %i\trow: %i\n", verif_left_view_row(tab, row, 4, viewl), viewl, row);
	printf("verif right view. result: %i\tviewr: %i\trow: %i\n", verif_right_view_row(tab, row, 4, viewr), viewr, row);
	printf("verif unique row. result: %i\trow: %i\n", unique_row(tab, row, 4), row);
	printf("\n");
	*/
	if (!verif_left_view_row(tab, row, 4, viewl))
	{
		return (0);
	}
	if (!verif_right_view_row(tab, row, 4, viewr))
	{
		return (0);
	}
	if (!unique_row(tab, row, 4))
	{
		return (0);
	}
	return (1);
}

int	test_col(int **tab, int col, int viewu, int viewd)
{
	if (!verif_up_view_col(tab, col, 4, viewu))
		return (0);
	if (!verif_down_view_col(tab, col, 4, viewd))
		return (0);
	if (!unique_col(tab, col, 4))
		return (0);
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	int	**tab;
	tab = create_tab(4);
	int	a;
	int	i;
	int	b;
	a = verif_col(tab, 0, 4);
	b = verif_row(tab, 0, 4);
	i = 0;
	while (tab[2][i])
	{
		printf("%d\n", tab[i][0]);
		i++;
	}
	printf("%d\n", a);
	printf("%d\n",b );
	//printf("Test view col : %d\n", verif_view_row(tab, 0, 4, 4));
}*/
