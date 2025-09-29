/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 08:19:03 by alebedev          #+#    #+#             */
/*   Updated: 2025/09/23 09:07:36 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

int	match_space(FILE *f)
{
	int	x;

	x = fgetc(f);
	if (x == EOF)
		return (-1);
	while (isspace(x))
		x = fgetc(f);
	ungetc(x, f);
	return (1);
}

int	scan_char(FILE *f, va_list ap)
{
	int		x;
	char	*out;

	x = fgetc(f);
	out = va_arg(ap, char *);
	if (x == EOF)
		return (-1);
	*out = x;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int	x;
	int	xx;
	int	*out;
	int	res;
	int	sign;

	x = fgetc(f);
	out = va_arg(ap, int *);
	res = 0;
	sign = 1;
	if (x == '-' || x == '+')
	{
		if (x == '-')
			sign = -1;
		xx = fgetc(f);
		if (!isdigit(xx))
		{
			ungetc(xx, f);
			ungetc(x, f);
			return (0);
		}
		x = xx;
	}
	if (!isdigit(x))
	{
		ungetc(x, f);
		return (0);
	}
	while (isdigit(x))
	{
		res = res * 10 + (x - 48);
		x = fgetc(f);
	}
	*out = res * sign;
	ungetc(x, f);
	return (1);
}

int	scan_string(FILE *f, va_list ap)
{
	int		x;
	char	*s;
	int		i;

	x = fgetc(f);
	s = va_arg(ap, char *);
	i = 0;
	if (x == EOF || isspace(x))
	{
		ungetc(x, f);
		return (-1);
	}
	while (!isspace(x) && x != EOF)
	{
		s[i++] = x;
		x = fgetc(f);
	}
	s[i] = '\0';
	ungetc(x, f);
	return (1);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
	case 'c':
		return (scan_char(f, ap));
	case 'd':
		/* match_space(f); */
		return (scan_int(f, ap));
	case 's':
		/* match_space(f); */
		return (scan_string(f, ap));
	default:
		return (-1);
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)

{
	int nconv;
	int c;

	nconv = 0;
	c = fgetc(f);
	if (c == EOF)
		return (EOF);
	ungetc(c, f);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break ;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break ;
		}
		format++;
	}
	if (ferror(f))
		return (EOF);
	return (nconv);
}

int	ft_scanf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vfscanf(0, format, ap);
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int		a;
	int		ret;
	char	c;
	char	s[100];

	printf("Test: %%d %%c %%s\n");
	ret = scanf("%d %c %s", &a, &c, s);
	printf("ret=%d, a=%d, c='%c', s='%s'\n", ret, a, c, s);
	return (0);
}
