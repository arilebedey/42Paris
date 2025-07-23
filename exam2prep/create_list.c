/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:22:29 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/19 19:37:26 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;

t_list	*create_list(int n)
{
	t_list	*head;
	t_list	*prev;
	t_list	*new;
	int		i;

	i = 0;
	while (i < n)
	{
		new = malloc(sizeof(t_list));
		new->data = i;
		new->next = NULL;
		if (!head)
			head = new;
		else
			prev->next = new;
		prev = new;
		i++;
	}
	return (head);
}
