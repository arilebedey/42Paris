
char	*sorted_string(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i] > s[i + 1])
		{
			ft_swap(&s[i], &s[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (s);
}

int	next_permutations(char *s, int len)
{
	int	i;

	i = len - 2;
	while (i >= 0 && s[i] > s[i + 1])
		i--;
	if (i < 0)
		return (0);
}
