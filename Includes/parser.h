/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:45:05 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/04 17:16:44 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

int				parse_envp(t_tools *tools);
char			*find_path(char **envp);
int				find_pwd(t_tools *tools);
int				parser(t_tools *tools);

//parser_utils
t_parser_tools	init_parser_tools(t_lexer *lexer_list, t_tools *tools);
void			count_pipes(t_lexer *lexer_list, t_tools *tools);
int				count_args(t_lexer *lexer_list);
t_lexer			*find_next_cmd(t_lexer *lexer_lst);

//handle_redirections
int				add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools);
int				handle_heredoc(t_parser_tools *parser_tools, t_lexer *tmp);
void			rm_redirections(t_parser_tools *parser_tools);

#endif