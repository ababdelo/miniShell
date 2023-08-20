/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:29:57 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 18:56:32 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, char c)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return ((&s[i]));
		i++;
	}
	return (0);
}
