/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:53:36 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/11 22:43:02 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

void	ft_parser(char *str)
{
	char **args;
	char *norm_str;
	int i = -1;
	// printf("old line: %s\n",str);
	norm_str = str_norm(str);
	printf("new line: %s\n",norm_str);
	args = ft_split(norm_str, '|');
	while (args[++i])
		printf("%s\n", args[i]);
}