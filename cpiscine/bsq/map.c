#include "bsq.h"

int	check_map_validity(char **map, char *info)
{
	int	y;
	int	x;
	int	first_lign_len;
	int	lign_len;

	y = 0;
	x = 0;
	first_lign_len = 0;
	while (map[y][x])
	{
		if (map[y][x] != info[0] && map[y][x] != info[1])
		{
			ft_putstr("ok\n");
			return (0);
		}
		first_lign_len++;
		x++;
	}
	while (map[++y])
	{
		x = 0;
		lign_len = 0;
		while (map[y][x] && map[y][x] != 4)
		{
			if (map[y][x] != info[0] && map[y][x] != info[1])
				return (0);
			lign_len++;
			x++;
		}
		if (lign_len != first_lign_len)
			return (0);
	}
	return (1);
}

int	check_nl_on_start(t_buff buff)
{
	int	i;
	int	nl_delay;
	int	save_delay;
	int	first;

	first = 1;
	i = -1;
	nl_delay = 0;
	save_delay = -1;
	while (buff.str[++i])
	{
		if (buff.str[i] == '\n')
		{
			if (nl_delay != save_delay && !first)
				return (0);
			first = 0;
			save_delay = nl_delay;
			nl_delay = 0;
		}
		else
		{
			nl_delay++;
		}
	}
	return (1);
}

char	**i_map(char ***map_pt, t_buff buff, int fd, char *info)
{
	int		i;
	int		f_bytes_read;
	int		nl_count;
	char	c[1];
	int		readed;
	
	nl_count = 0;
	i = -1;
	readed = 0;
	f_bytes_read = 1;
	while (f_bytes_read > 0)
	{
		f_bytes_read = read(fd, c, 1);
		if (f_bytes_read <= 0)
			break;
		if (c[0] == '\n')
		{
			if (!readed)
				return (0);
			else
				nl_count++;
		}
		readed = 1;
		buff.str[++i] = c[0];
	}
	if (!readed)
		return (0);
	if (!check_nl_on_start(buff))
		return (0);
	*map_pt = malloc(sizeof(char *) * (nl_count + 1));
	*map_pt = ft_split2(buff.str, "\n");
	if (!check_map_validity(*map_pt, info))
	{
		ft_putstr("checkmap\n");
		return (0);
	}
	return (*map_pt);
}

char	**term_i_map(char ***map_pt, t_buff buff, char *info)
{
	int		i;
	int		f_bytes_read;
	int		nl_count;
	char	c[1];
	int		readed;
	
	nl_count = 0;
	i = -1;
	readed = 0;
	f_bytes_read = 1;
	while (f_bytes_read > 0)
	{
		f_bytes_read = read(0, c, 1);	
		if (f_bytes_read <= 0)
			break;
		if (c[0] == '\n')
		{
			if (!readed)
				return (0);
			else
				nl_count++;
		}
		readed = 1;
		buff.str[++i] = c[0];
	}
	if (!readed)
		return (0);
	if (!check_nl_on_start(buff))
		return (0);
	*map_pt = malloc(sizeof(char *) * (nl_count + 1));
	*map_pt = ft_split2(buff.str, "\n");
	if (!check_map_validity(*map_pt, info))
		return (0);
	return (*map_pt);
}

void	put_sq_in_map(char **map, t_bsq sqr, char *info)
{
	int	y;
	int	x;
	
	if (sqr.x == -1)
		return ;
	y = sqr.y - 1;
	x = sqr.x - 1;
	if (sqr.x == -1)
		return ;
	while (++y < sqr.y + sqr.size)
	{
		x = sqr.x - 1;
		while (++x < sqr.x + sqr.size)
		{
			map[y][x] = info[2];
		}
	}
}

void	print_map(char **map_pt)
{
	int	i;

	i = -1;
	while (map_pt[++i])
	{
		ft_putstr(map_pt[i]);
		write(1, "\n", 1);
	}
}
