/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:53:36 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/11 23:57:37 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

void	ft_parser(char *str)
{
	char **parts;
	char **words;
	char *norm_str;
	int i = -1,j = -1;
	printf("old line: %s\n",str);
	norm_str = str_norm(str);
	printf("new line: %s\n\n\n",norm_str);
	parts = ft_split(norm_str, '|');
	while (parts[++i])
	{
		printf("parts[%d]:%s\n",i, parts[i]);
			words = ft_split(parts[i], ' ');
		j = -1;
		while (words[++j])
		printf("words[%d]:%s\n",j, words[j]);
	}
}