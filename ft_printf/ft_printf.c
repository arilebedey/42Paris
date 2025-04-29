/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:10:47 by alebedev          #+#    #+#             */
/*   Updated: 2025/04/29 17:04:37 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <__stdarg_va_list.h>

int	ft_printf(const char *print_spec, ...)
{
	va_list	args;
}

int	main(void)
{
	int	n;

	n = 1;
	printf("%d\n", ft_printf("I am hello %i\n", n));
}
