/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:28:26 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/21 17:43:29 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "minishell.h"

void	parser_error(int error, t_tools *tools, t_lexer *lexer_list);
int		parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
			t_tokens token);
void	lexer_error(int error, t_tools *tools);
int		cmd_not_found(char *str);
int		export_error(char *c);

//ft_error
int		ft_error(int error, t_tools *tools);

#endif
