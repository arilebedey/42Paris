/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agense <agense@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:37:41 by agense            #+#    #+#             */
/*   Updated: 2025/02/05 19:30:51 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H

# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_bsq
{
	int	y;
	int	x;
	int	size;
	int	steps;
}				t_bsq;

typedef struct s_buff
{
	char	*str;
	int		size;
}				t_buff;

//buff.c
void	clean_buff(t_buff buff);
t_buff	i_buff(t_buff *buff_pt);

//map.c
char	**i_map(char ***map_pt, t_buff buff, int fd, char *info);
char	**term_i_map(char ***map_pt, t_buff buff, char *info);
void	put_sq_in_map(char **map, t_bsq sqr, char *info);
void	print_map(char **map_pt);

//info.c
int		term_put_info_in_buf(t_buff buff);
char	*take_info(t_buff buff, int *lign_info);
int		put_info_in_buf(t_buff buff, int fd);

// ft_find.c
t_bsq	ft_find(char **map, char *info);

//utile.c
int		count_lines(char *str);
int		is_nbr(char c);
int		is_printable(char c);

// ft_putstr.c
void	ft_putstr(char *str);

//ft_atoi.c
int		get_atoi(char *str, int index, int negative);
int		ft_atoi(char *str);

//strdup.c
char	*ft_strdup(char *src);

//ft_split.c
int		is_separator(char c, char *charset);
int		count_words(char *str, char *charset);
char	*take_word(char *str, char *charset, char *split_strstr, int i);
void	init_var(int *i, int *j, int *word_det);
char	**ft_split(char *str, char *charset);
char	**ft_split2(char *str, char *charset);

//ft_putstr_non_printable
void	ft_putchar(char c);
void	dec_to_hexa(int dec_nbr, char *hexa_str);
void	ft_putstr_non_printable(char *str);

// ft_lengths.c
int		getlineidx(char **map);
int		getmapidx(char **map);
int		ft_strlen(char *str);

// ft_lastpos.c
int		max_steps(char **map, char *info);
int		*frst_testable(char **map, char *info);
int		*last_testable(char **map, char *info);
int		is_last(int y, int x, int *last);

// ft_nextpos.c
int		ft_newpos_ovrwrt(char **map, t_bsq *sqr, char *info);
int		*ft_newpos_check(char **map, t_bsq sqr, char *info, int was_incrm);

// ft_check_square.c
int		ft_check_square(char **map, t_bsq sqr, char *info);

// ft_enlarge.c
t_bsq	*ft_enlarge_ovrwrt(t_bsq *sqr);
int		ft_enlarge_check(char **map, t_bsq sqr);

// ft_swap_sqrs.c
void	ft_swap_sqrs(t_bsq *best, t_bsq *sqr);

//error.c
void	write_error(void);

#endif
