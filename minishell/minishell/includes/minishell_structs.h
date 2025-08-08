/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:09:20 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/08 19:05:33 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCTS_H
# define MINISHELL_STRUCTS_H

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_OUT,
}					t_token_type;

/* text: word text or operator symbol */
typedef struct s_token
{
	t_token_type	type;
	char			*text;
	struct s_token	*next;
}					t_token;

/* Abstract Syntax Tree node */
typedef struct s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	t_token			*tok;
}					t_tree;

typedef struct s_ms
{
	t_tree			*ast;
	char			**env;
}					t_ms;

#endif
