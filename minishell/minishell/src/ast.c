/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:46:22 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/08 18:26:14 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* create a tree node */
static t_tree	*new_node(t_token *tok)
{
	t_tree	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->tok = tok;
	return (node);
}

/* find the rightmost separator of given type */
static t_token	*find_sep(t_token *tok, t_token_type type)
{
	t_token	*cur;
	t_token	*last;

	cur = tok;
	last = NULL;
	while (cur)
	{
		if (cur->type == type)
			last = cur;
		cur = cur->next;
	}
	return (last);
}

static t_tree	*build(t_token *tok, t_token_type sep)
{
	t_token	*s;
	t_token	*right;
	t_tree	*n;

	s = find_sep(tok, sep);
	if (!s)
		return (NULL);
	right = s->next;
	s->next = NULL;
	n = new_node(s);
	if (!n)
		return (NULL);
	n->left = build_ast(tok);
	n->right = build_ast(right);
	return (n);
}

/* lowest‐precedence first, aka PIPE */
t_tree	*build_ast(t_token *tok)
{
	t_tree	*n;

	if (!tok)
		return (NULL);
	n = build(tok, T_PIPE);
	if (n)
		return (n);
	n = build(tok, T_REDIR_OUT);
	if (n)
		return (n);
	return (new_node(tok));
}

void	free_ast(t_tree *r)
{
	if (!r)
		return ;
	free_ast(r->left);
	free_ast(r->right);
	free(r);
}
