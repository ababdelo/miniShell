/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_re_split_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:27:26 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/01 14:34:20 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_re_split_str(char **arr)
{
	char	**ret;
	char	*joined_str;

	joined_str = ft_join_split_str(arr, NULL);
	free_arr(arr);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	joined_str = ft_join_split_str(ret, NULL);
	free_arr(ret);
	ret = ft_split(joined_str, ' ');
	free(joined_str);
	return (ret);
}
