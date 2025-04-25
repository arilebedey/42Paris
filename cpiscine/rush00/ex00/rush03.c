/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:12:53 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/18 15:45:23 by rchan-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define C_FIRSTLINE_BEGIN 'A'
#define C_FIRSTLINE_MID 'B'
#define C_FIRSTLINE_END 'C'
#define C_INTERMEDIARY 'B'
#define C_LASTLINE_BEGIN 'A'
#define C_LASTLINE_MID 'B'
#define C_LASTLINE_END 'C'

void	ft_putchar(char c);

static void	print_line(char begin, char mid, char end, int n)
{
	int	count;

	count = 0;
	while (count <= n - 1)
	{
		if (count == 0)
		{
			ft_putchar(begin);
			count++;
		}
		if (count < n - 1)
		{
			ft_putchar(mid);
			count++;
		}
		if (count == n - 1)
		{
			ft_putchar(end);
			count++;
		}
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	count;

	if (x <= 0 || y <= 0)
		return ;
	count = 0;
	while (count <= y - 1)
	{
		if (count == 0)
		{
			print_line(C_FIRSTLINE_BEGIN, C_FIRSTLINE_MID, C_FIRSTLINE_END, x);
			count++;
		}
		if (count < y - 1)
		{
			print_line(C_INTERMEDIARY, ' ', C_INTERMEDIARY, x);
			count++;
		}
		if (count == y - 1)
		{
			print_line(C_LASTLINE_BEGIN, C_LASTLINE_MID, C_LASTLINE_END, x);
			count++;
		}
	}
}
