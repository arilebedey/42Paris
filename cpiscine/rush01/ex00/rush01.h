/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 09:54:24 by lengarci          #+#    #+#             */
/*   Updated: 2025/01/26 22:17:28 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>
//Fichier split / atoi qui servira a recuperer les donnees utilisateurs
char	**ft_split(char *str, char *charset);
int	ft_atoi(char *str);
//fichier tab qui servira a creer le tableau et faire certains tests
int	**create_tab(int n);
int	test_col(int **tab, int col, int viewu, int viewd);
int	test_row(int **tab, int row, int viewl, int viewr);
//fichier qui sert a verifier les vues ligne et colonne 1 par 1
int	verif_left_view_row(int **tab, int row, int n, int view);
int	verif_right_view_row(int **tab, int row, int n, int view);
int	verif_up_view_col(int **tab, int col, int n, int view);
int	verif_down_view_col(int **tab, int col, int n, int view);
//toute fonction pouvant etre utiles dans le fichier utils.c
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_putnbr(int nb);
//generations
void    next_permutation(int *arr, int n, int *count);
int	gentab(int **tab, int **tab_back, int *values);
void	genrow(int **tab, int row);


#endif
