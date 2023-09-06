/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:14:59 by elel-yak          #+#    #+#             */
/*   Updated: 2023/09/04 17:17:00 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

size_t	dollar_sign(char *str);
size_t	equal_sign(char *str);
size_t	quotes_lenght(char *str);

int		after_dol_lenght(char *str, int j);
int		question_mark(char **tmp);
int		loop_if_dollar_sign(t_tools *tools, char *str, char **tmp, int j);
int		handle_digit_after_dollar(int j, char *str);

char	*char_to_str(char c);
char	*delete_quotes(char *str, char c);
char	*detect_dollar_sign(t_tools *tools, char *str);
char	*expand_str(t_tools *tools, char *str);

char	**expand(t_tools *tools, char **str);

#endif
