#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

/* ---------- forward declarations ---------- */
int	match_space(FILE *f);
int	match_char(FILE *f, char expected);
int	scan_char(FILE *f, va_list *ap);
int	scan_int(FILE *f, va_list *ap);
int	scan_string(FILE *f, va_list *ap);
int	match_conv(FILE *f, const char **fmt, va_list *ap);
int	ft_vfscanf(FILE *f, const char *fmt, va_list ap);
int	ft_scanf(const char *fmt, ...);

/* ---------- unchanged helpers ---------- */
int	match_space(FILE *f)
{
	int	c;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	while (isspace(c))
		c = fgetc(f);
	ungetc(c, f);
	return (1);
}

int	match_char(FILE *f, char expected)
{
	int	c;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	if (c == expected)
		return (1);
	ungetc(c, f);
	return (0);
}

/* ---------- rewritten scanners that take va_list* ---------- */
int	scan_char(FILE *f, va_list *ap)
{
	int		c;
	char	*out;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	out = va_arg(*ap, char *);
	*out = (char)c;
	return (1);
}

int	scan_int(FILE *f, va_list *ap)
{
	int	*out;

	int c, sign = 1, result = 0;
	out = va_arg(*ap, int *);
	/* skip leading white-space */
	do
	{
		c = fgetc(f);
		if (c == EOF)
			return (-1);
	} while (isspace(c));
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		c = fgetc(f);
	}
	if (!isdigit(c))
	{
		if (c != EOF)
			ungetc(c, f);
		return (0);
	}
	while (isdigit(c))
	{
		result = result * 10 + (c - '0');
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	*out = sign * result;
	return (1);
}

int	scan_string(FILE *f, va_list *ap)
{
	int		c;
	char	*s;
	int		i;

	c = fgetc(f);
	s = va_arg(*ap, char *);
	i = 0;
	if (c == EOF || isspace(c))
	{
		if (c != EOF)
			ungetc(c, f);
		return (0);
	}
	while (c != EOF && !isspace(c))
	{
		s[i++] = (char)c;
		c = fgetc(f);
	}
	s[i] = '\0';
	if (c != EOF)
		ungetc(c, f);
	return (1);
}

/* ---------- dispatcher ---------- */
int	match_conv(FILE *f, const char **fmt, va_list *ap)
{
	int	res;

	switch (**fmt)
	{
	case 'c':
		res = scan_char(f, ap);
		break ;
	case 'd':
		match_space(f);
		res = scan_int(f, ap);
		break ;
	case 's':
		match_space(f);
		res = scan_string(f, ap);
		break ;
	case '\0':
		return (-1);
	default:
		return (-1);
	}
	(*fmt)++;
	return (res);
}

/* ---------- public functions ---------- */
int	ft_vfscanf(FILE *f, const char *fmt, va_list ap)
{
	int	nconv;

	nconv = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (match_conv(f, &fmt, &ap) != 1)
				break ;
			nconv++;
		}
		else if (isspace(*fmt))
		{
			if (match_space(f) == -1)
				break ;
			fmt++;
		}
		else if (match_char(f, *fmt) != 1)
			break ;
		else
			fmt++;
	}
	return (ferror(f) ? EOF : nconv);
}

int	ft_scanf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = ft_vfscanf(stdin, fmt, ap);
	va_end(ap);
	return ret;
}

/* ---------- demo ---------- */
int	main(void)
{
	int		a;
	char	c;
	char	s[100];
	int		ret;

	printf("Enter input like: 42 X hello\n");
	ret = ft_scanf("%d %c %s", &a, &c, s);
	printf("ret=%d, a=%d, c='%c', s=\"%s\"\n", ret, a, c, s);
	return 0;
}
