/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:07:50 by alebedev          #+#    #+#             */
/*   Updated: 2025/02/04 14:22:10 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	getlineidx(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	i--;
	return (i);
}

int	getmapidx(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i][0])
		i++;
	i--;
	return (i);
}
