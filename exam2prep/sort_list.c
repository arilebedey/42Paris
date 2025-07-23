/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:37:17 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/19 19:43:18 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list				*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int	ascending(int a, int b)
{
	return (a <= b);
}
*/

#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;

int	count_nodes(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*cur;
	int		sorted;
	int		tmp;

	sorted = 0;
	if (!lst)
		return (NULL);
	while (!sorted)
	{
		cur = lst;
		sorted = 1;
		while (cur->next)
		{
			if ((*cmp)(cur->data, cur->next->data) != 0)
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
				sorted = 0;
			}
			cur = cur->next;
		}
	}
	return (lst);
}
