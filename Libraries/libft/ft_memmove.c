/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:27:46 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 19:00:36 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == 0 && dst == 0)
		return (0);
	if (dst < src)
	{
		while (n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
			n--;
		}
	}
	else
	{
		while (n)
		{
			((char *)dst)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dst);
}
