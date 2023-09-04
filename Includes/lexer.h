/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:43:53 by elel-yak          #+#    #+#             */
/*   Updated: 2023/09/04 17:16:50 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

int			handle_quotes(int i, char *str, char del);
int			handle_token(char *str, int i, t_lexer **lexer_list);
t_tokens	check_token(int c);
t_lexer		*ft_lexerclear_one(t_lexer **lst);
void		ft_lexerdel_first(t_lexer **lst);
void		ft_lexerdelone(t_lexer **lst, int key);
void		ft_lexerclear(t_lexer **lst);
t_lexer		*ft_lexernew(char *str, int token);
void		ft_lexeradd_back(t_lexer **lst, t_lexer *new);
int			add_node(char *str, t_tokens token,
				t_lexer **lexer_list);
int			read_words(int i, char *str, t_lexer **lexer_list);
int			token_reader(t_tools *tools);

#endif
