/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:58:56 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/12 16:05:20 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

int	sval_initializer(t_splitval *splitval, char *str, char sep)
{
	splitval->cntr =  word_cnt(str, sep);
	splitval->pos = sep_pos(str, sep, splitval->cntr);
	splitval->ret = malloc(sizeof(char*) * (splitval->cntr + 2));
	if (!splitval->ret)
		return 0;
	splitval->len = 0;
	splitval->wrd_len = -1;
	splitval->str_index = -1;
	splitval->pos_index = 0;
	splitval->ret_index = 0;
	splitval->index = -1;
	return 1;
}
