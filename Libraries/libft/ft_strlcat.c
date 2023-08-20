/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:32:14 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:32:21 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	i = len_dst;
	if (len_dst > dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] && i < (dstsize - 1) && dstsize > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len_dst + ft_strlen(src));
}
