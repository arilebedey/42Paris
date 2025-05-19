#include "../includes/push_swap.h"

void	clear_list(t_opnode **list)
{
	t_opnode	*current;
	t_opnode	*next;

	if (!list || !*list)
		return ;
	current = *list;
	while (current) {
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}
