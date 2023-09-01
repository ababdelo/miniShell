/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:09:02 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/01 12:29:13 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	char	**rtn;
	int		i;

	i = -1;
	while (arr[++i])
		;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = -1;
	while (arr[++i])
	{
		rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_arr(rtn);
			return (rtn);
		}
	}
	return (rtn);
}
