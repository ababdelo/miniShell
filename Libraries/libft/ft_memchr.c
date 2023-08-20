/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:27:08 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:27:17 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&(((unsigned char *)s)[i]));
		n--;
		i++;
	}
	return (0);
}
