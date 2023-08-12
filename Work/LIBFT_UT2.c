/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIBFT_UT2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:32 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/12 16:06:06 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

void split_prt2(t_splitval *splitval, char *str)
{
	while (str[++splitval->str_index])
	{
		if (splitval->str_index < splitval->pos[splitval->pos_index])
			splitval->ret[splitval->ret_index][++splitval->index] = str[splitval->str_index];
		else
		{
			splitval->ret[splitval->ret_index][++splitval->index] = '\0';
			if(splitval->pos_index < splitval->cntr)
				splitval->pos_index++;
			if(splitval->ret_index < splitval->cntr)
				splitval->ret_index++;
			splitval->index = -1;
		}
	}
	splitval->ret[splitval->ret_index][++splitval->index] = '\0';
	splitval->ret[++splitval->ret_index] = NULL;
}

char **split_prt1(char *str, char sep, t_splitval *splitval)
{
	if (!sval_initializer(splitval, str, sep))
		return NULL;
	splitval->cntr+=1;
	while (++splitval->str_index < splitval->cntr)
	{
		splitval->wrd_len = ft_wrdlen(&str[splitval->len], sep);
		splitval->len += splitval->wrd_len+1;
		splitval->ret[splitval->str_index] = malloc(sizeof(char) * splitval->wrd_len + 1);
		if (!splitval->ret[splitval->str_index])
			return NULL;
	}
	splitval->str_index = -1;
	split_prt2(splitval, str);
	free(splitval->pos);
	return splitval->ret;
}
