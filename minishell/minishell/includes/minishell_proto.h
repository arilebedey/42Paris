/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_proto.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebedev <alebedev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:11:42 by alebedev          #+#    #+#             */
/*   Updated: 2025/08/08 21:38:55 by alebedev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PROTO_H
# define MINISHELL_PROTO_H

# include "minishell_structs.h"

/* ROOT FOLDER */
// lexer.c
t_token	*lexer(const char *line);
void	free_tokens(t_token *tok);
// ast.c
t_tree	*build_ast(t_token *tok);
void	free_ast(t_tree *root);

/* EXEC */
// cmd.c
char	**find_path(char **env);
char	**get_cmd(char **paths, char *cmd);
// exec.c
int		exec_ast(t_ms *ms, t_tree *root);

/* FREE */
// free_tab.c
void	free_tab(char **tab);

#endif
