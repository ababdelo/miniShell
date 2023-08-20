/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:34:29 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:34:38 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			while (i > 0)
			{
				s++;
				i--;
			}
			return ((char *)s);
		}
		i--;
	}
	while (*s)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
