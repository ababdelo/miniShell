/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIBFT_UT1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:26 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/11 17:32:19 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

// int	wrd_cnt(char const *s, char del)
// {
// 	int	index;
// 	int	count;

// 	index = -1;
// 	count = 0;
// 	while (s[++index] != '\0')
// 	{
// 		helper(&index, s);
// 		if(s[index] == del)
// 			count++;
// 	}
// 	// printf("------------ [%d] ------------\n", count+1);
// 	return (count+1);
// }

// char	**ft_free(char **str, int x)
// {
// 	while (x >= 0)
// 	{
// 		free(str[x]);
// 		x--;
// 	}
// 	free(str);
// 	return (NULL);
// }

void	helper(int *index, char const *str)
{
	if (str[(*index)] == '\'')
	{
		while (str[++(*index)] != '\'');
		(*index)++;
	}
	if (str[(*index)] == '"')
	{
		while (str[++(*index)] != '"');
		(*index)++;
	}
}



// char	**ft_split(char const *s, char c)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**str;

// 	i = 0;
// 	k = 0;
// 	str = (char **)malloc((wrd_cnt(s, c) + 1) * sizeof(char *));
// 	if (!str)
// 		return (NULL);
// 	while (k < wrd_cnt(s, c))
// 	{
// 		helper(&i, s);
// 		while (s[i] == c && s[i] != '\0')
// 			i++;
// 		j = i;
// 		while (s[i] != c && s[i] != '\0')
// 			i++;
// 		str[k] = ft_substr(s, j, i - j);
// 		if (!str[k])
// 			return (ft_free(str, k));
// 		k++;
// 	}
// 	str[k] = NULL;
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*ptr;
// 	size_t	size;
// 	size_t	val;

// 	if (!s)
// 		return (NULL);
// 	size = ft_strlen(s);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (size - start >= len)
// 		val = len + 1;
// 	else
// 		val = size - start + 1;
// 	ptr = malloc(val * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	if (len >= SIZE_MAX)
// 		ft_strlcpy(ptr, &s[start], size +1);
// 	else
// 		ft_strlcpy(ptr, (s + start), (len + 1));
// 	return (ptr);
// }
