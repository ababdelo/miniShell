/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 04:55:11 by elel-yak          #+#    #+#             */
/*   Updated: 2023/09/04 17:53:38 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	dollar_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*char_to_str(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char), 2);
	str[0] = c;
	return (str);
}

int	after_dol_lenght(char *str, int j)
{
	int	i;

	i = j + 1;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' '
		&& str[i] != '\"' && str[i] != '\'' && str[i] != '=' && str[i] != '-'
		&& str[i] != ':' && str[i] != '@' && str[i] != '#' && str[i] != '%'
		&& str[i] != '^' && str[i] != '&' && str[i] != '*' && str[i] != '('
		&& str[i] != ')' && str[i] != '/' && str[i] != '<' && str[i] != '>'
		&& str[i] != ',' && str[i] != '.' && str[i] != '~' && str[i] != '`'
		&& str[i] != '{' && str[i] != '}' && str[i] != '[' && str[i] != ']'
		&& str[i] != '!' && !(str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

size_t	quotes_lenght(char *str)
{
	int		i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ret++;
		}
		i++;
	}
	return (ret);
}
