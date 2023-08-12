/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:53:36 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/12 17:33:12 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

void	ft_parser(char *str, t_splitval *splitval)
{
	char **parts;
	char **words;
	char *norm_str;
	int i = -1,j = -1;
	printf("\n[+] Old line: %s\n",str);
	norm_str = str_norm(str);
	printf("\n[+] New line: %s\n\n",norm_str);
	parts = split_prt1(norm_str, '|', splitval);
	while (parts[++i])
	{
		printf("/*********************************************************/\n");
		printf("\n[+] Parts[%d]:%s\n\n",i, parts[i]);
			words = split_prt1(parts[i], ' ', splitval);
		j = -1;
		while (words[++j])
			printf("\t[-] Words[%d]:%s\n",j, words[j]);
		printf("\n/***********************************************************/\n\n");
	}
}
