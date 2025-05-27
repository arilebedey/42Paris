/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:48:23 by alebedev          #+#    #+#             */
/*   Updated: 2025/05/27 11:06:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_list(t_opnode **list)
{
	t_opnode	*current;
	t_opnode	*next;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}

t_opnode	*new_opnode(void *operation)
{
	t_opnode	*node;

	node = malloc(sizeof(t_opnode));
	if (!node)
		return (NULL);
	node->operation = operation;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_opnode_back(t_opnode **lst, t_opnode *to_add)
{
	t_opnode	*last;

	if (!to_add)
		return ;
	if (!lst || !*lst)
	{
		*lst = to_add;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = to_add;
	to_add->prev = last;
}
