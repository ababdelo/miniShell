/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIBFT_UT1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:26 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/12 16:01:59 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

void	helper(int *index, char const *str)
{
	if (str[(*index)] == '\'')
	{
		while (str[++(*index)] != '\'' && str[(*index)]);
		if(str[(*index)] == '\'')
			(*index)++;
	}
	if (str[(*index)] == '"' )
	{
		while (str[++(*index)] != '"' && str[(*index)]);
		if(str[(*index)] == '\'')
			(*index)++;
	}
}

size_t	ft_strlen(char const *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
		index++;
	return (index);
}

int	word_cnt(char const *s, char del)
{
	int	index;
	int	count;

	index = -1;
	count = 0;
	while (s[++index] != '\0')
	{
		helper(&index, s);
		if(s[index] == del && s[index] != '\0')
			count++;
	}
	return (count);
}

int	*sep_pos(char const *str, char sep, int cntr)
{
	
	int *pos;
	int index = -1;
	int pindex = -1;
	pos = malloc(sizeof(int) * (cntr+1));
	if (!pos)
		return NULL;
	while (str[++index])
	{
		helper(&index, str);
		if (str[index] == sep && str[index] != '\0')
			pos[++pindex] = index;
	}
	pos[++pindex] = index;
	return pos;
}

size_t	ft_wrdlen(char const *str, char sep)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] && str[index] != sep)
	{
		helper(&index, str);
		if(str[index] != '\0')
			++index;
	}
	return (index);
}
