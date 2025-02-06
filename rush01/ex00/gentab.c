/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gentab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:36:07 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/26 22:45:00 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

int	test_cols(int **tab, int until, int *values)
{
	int	i;
	int viewu;
	int viewd;

	i = 0;
	while (i <= until)
	{
		viewu = i;
		viewd = i + 4;
		if (!test_col(tab, i, values[viewu], values[viewd]))
			return (0);
		i++;
	}
	return (1);
}

int	test_rows(int **tab, int until, int *values)
{
	int	i;
	int viewl;
	int viewr;

	i = 0;
	while (i <= until)
	{
		viewl = i + 8;
		viewr = i + 12;
		if (!test_row(tab, i, values[viewl], values[viewr]))
			return (0);
		i++;
	}
	return (1);
}

void	genrow(int **tab, int row)
// Fonction qui genere la combine lexicographique
// suivante sur une des 4 lignes (row)
{
	next_permutation(tab[row], 4, tab[4]);
}

int	gentab(int **tab, int **tab_back, int *values)
// Fonction recursive qui genere une nouvelle ligne jusqu'a ce que les 4 ligne soient teste horizontalement, puis genere test les colonnes
{
	int	col;
	int	row;

	row = 0;
	while (row < 3 && test_rows(tab, row, values))
		row++;
	col = 0;
	while (col < 3 && test_cols(tab, row, values))
		col++;
	while (row < 4 && col < 4)
	{
		if (!test_rows(tab, row, values))
		{
			if (tab[4][0] == 24)
				return (0);
			genrow(tab, row);
			**tab = **tab_back;
			gentab(tab, tab_back, values);
		}
		else if (row == 3)
		{
			while (col < 4)
			{
				if (!test_cols(tab, col, values))
				{
				}
				if (col == 3)
					return (1);
				tab[4][0] = 0;
				col++;
			}
		}
		if (row != 3)
		{
			**tab_back = **tab;
			tab[4][0] = 0;
			row++;
		}
	}
	return (1);
}
