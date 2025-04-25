/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:24:11 by alebedev          #+#    #+#             */
/*   Updated: 2025/01/22 20:01:39 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_cal(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_al(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((is_cal(str[i]) && count > 0) || (is_al(str[i]) && count == 0))
		{
			if (str[i] >= 'A' && str[i] <= 'Z' && count > 0)
				str[i] = str[i] + 32;
			if (str[i] >= 'a' && str[i] <= 'z' && count == 0)
				str[i] = str[i] - 32;
			i++;
			count++;
			continue ;
		}
		if (!is_cal(str[i]) && !is_al(str[i]))
			count = 0;
		if (is_cal(str[i]) || is_al(str[i]) || is_nbr(str[i]))
			count++;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "AAA+sedaed SFEFE*fsefef 42JJJj";
	ft_strcapitalize(str);
	printf("%s\n", str);
}
*/
