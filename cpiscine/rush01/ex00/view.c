/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:48:39 by lengarci          #+#    #+#             */
/*   Updated: 2025/01/26 18:50:53 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

//verifie toute la colonne en partant de la vue de gauche
int	verif_left_view_row(int **tab, int row, int n, int view)
{
	int	count;
	int	i;
	int	j;
	int	tmp;

	count = 1;
	i = 0;
	tmp = tab[row][i];
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (tmp < tab[row][j])
			{
				count++;
				tmp = tab[row][j];
			}
			j++;
		}
		i++;
	}
	if (count == view)
		return (1);
	return (0);
}
//verifie toute la colonne en partant de la vue de droite
int	verif_right_view_row(int **tab, int row, int n, int view)
{
	int	count;
	int	i;
	int	j;
	int	tmp;

	count = 1;
	i = n - 1;
	tmp = tab[row][i];
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tmp < tab[row][j])
			{
				count++;
				tmp = tab[row][j];
			}
			j--;
		}
		i--;
	}
	if (count == view)
	{
		return (1);
	}
	return (0);
}
//verifie toute la colonne en partant de la vue d'en haut
int	verif_up_view_col(int **tab, int col, int n, int view)
{
	int	count;
	int	i;
	int	j;
	int	tmp;

	count = 1;
	i = 0;
	tmp = tab[0][col];
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (tmp < tab[j][col])
			{
				count++;
				tmp = tab[j][col];
			}
			j++;
		}
		i++;
	}
	if (count == view)
		return (1);
	return (0);
}
//verifie toute la colonne en partant de la vue d'en bas
int	verif_down_view_col(int **tab, int col, int n, int view)
{
	int	count;
	int	i;
	int	j;
	int	tmp;

	count = 1;
	i = n - 1;
	tmp = tab[0][i];
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (tmp < tab[j][col])
			{
				count++;
				tmp = tab[j][col];
			}
			j--;
		}
		i--;
	}
	if (count == view)
		return (1);
	return (0);
}
