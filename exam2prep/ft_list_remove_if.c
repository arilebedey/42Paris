/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_mine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:00:38 by alebedev          #+#    #+#             */
/*   Updated: 2025/07/23 19:21:44 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
$>

*/

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *data, void *data_ref))
{
	t_list	*curr;
	t_list	*prev;
	t_list	*temp;

	if (!begin_list || !*begin_list)
		return ;
	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			temp = curr;
			if (prev)
				prev->next = curr->next;
			else
				*begin_list = curr->next;
			curr = curr->next;
			free(temp->data);
			free(temp);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}
