/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:35:29 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:35:35 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			strln;

	strln = ft_strlen(s);
	if (!s)
		return (0);
	if (start > strln)
		return (ft_strdup(""));
	if (len > strln - start)
		return (ft_strdup(s + start));
	i = 0;
	substr = (char *)malloc((len * sizeof(char)) + 1);
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
