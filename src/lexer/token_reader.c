/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:50:35 by elel-yak          #+#    #+#             */
/*   Updated: 2023/09/04 17:15:34 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_node(char *str, t_tokens token, t_lexer **lexer_list)
{
	t_lexer	*node;

	node = ft_lexernew(str, token);
	if (!node)
		return (0);
	ft_lexeradd_back(lexer_list, node);
	return (1);
}

int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_token(str[i + j])))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (ft_is_wide_space(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

int	token_reader(t_tools *tools)
{
	int		i;
	int		j;

	i = 0;
	while (tools->args[i])
	{
		j = 0;
		i += ft_skip_spaces(tools->args, i);
		if (check_token(tools->args[i]))
			j = handle_token(tools->args, i, &tools->lexer_list);
		else
			j = read_words(i, tools->args, &tools->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}
