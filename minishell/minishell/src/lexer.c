/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:37:05 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/05 19:40:30 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*d;

	d = malloc(n + 1);
	if (!d)
		return (NULL);
	memcpy(d, s, n);
	d[n] = '\0';
	return (d);
}

static t_token	*new_tok(t_token_type type, const char *start, int len)
{
	t_token	*t;

	t = malloc(sizeof(*t));
	if (!t)
		return (NULL);
	t->type = type;
	t->text = ft_strndup(start, len);
	t->next = NULL;
	return (t);
}

t_token	*lexer(const char *line)
{
	t_token	*head;
	t_token	*tail;
	int		i;
	int		n;
	t_token	*t;
	int		j;

	head = NULL;
	tail = NULL;
	i = 0;
	n = strlen(line);
	while (i < n)
	{
		if (isspace((unsigned char)line[i]))
		{
			i++;
			continue ;
		}
		t = NULL;
		if (line[i] == '|')
			t = new_tok(T_PIPE, line + i++, 1);
		else if (line[i] == '>')
			t = new_tok(T_REDIR_OUT, line + i++, 1);
		else
		{
			j = i;
			while (j < n && !isspace((unsigned char)line[j]) && line[j] != '|'
				&& line[j] != '>')
				j++;
			t = new_tok(T_WORD, line + i, j - i);
			i = j;
		}
		if (!t)
			break ;
		if (!head)
		{
			head = t;
			tail = t;
		}
		else
		{
			tail->next = t;
			tail = t;
		}
	}
	return (head);
}

void	free_tokens(t_token *tok)
{
	t_token	*nx;

	while (tok)
	{
		nx = tok->next;
		free(tok->text);
		free(tok);
		tok = nx;
	}
}
