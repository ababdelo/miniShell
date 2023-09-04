/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:11:57 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/04 16:08:23 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

int				implement_tools(t_tools *tools);
int				reset_tools(t_tools *tools);
int				prepare_executor(t_tools *tools);
int				minishell_loop(t_tools *tools);
int				event(void);
void			sigint_handler(int sig);
void			sigquit_handler(int sig);
void			init_signals(void);
t_simple_cmds	*ft_simple_cmdsnew(char **str, int num_redirections,
					t_lexer *redirections);
void			ft_simple_cmdsadd_back(t_simple_cmds **lst, t_simple_cmds *new);
void			ft_simple_cmdsclear(t_simple_cmds **lst);
t_simple_cmds	*ft_simple_cmdsfirst(t_simple_cmds *map);
int				find_matching_quote(char *line, int i, int *num_del, int del);
int				count_quotes(char *line);
#endif