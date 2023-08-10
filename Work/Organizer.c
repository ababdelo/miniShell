/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:15:23 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/10 18:59:08 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

char *str_norm(char *str)
{
	int cntr = 0;
	int ret = 0;
	int len = ft_strlen(str);
	if(str[0] == '|' || str[len-1] == '|')
		return "pipe";
	else if( str[len-1] == '<')
		return "left_redirection";
	else if( str[len-1] == '>')
		return "left_redirection";
	ret = pipe_cntr(str);
	if (ret == -1)
		return "pipe_cntr";
	cntr += ret;
	ret = lredir_cntr(str);
	if (ret == -1)
	{
		ret = herd_cntr(str);
		if (ret == -1)
			return "pipe_cntr";
		cntr += ret;	
	}
	else
		cntr += ret;
	ret = rredir_cntr(str);
	if (ret == -1)
	{
		;
	}
	else
		cntr += ret;
	return (organizer(-1, -1, cntr, str));
}

char *organizer(int index, int nindex, int cntr, char *str)
{
	printf("%zu %d  %zu \n",ft_strlen(str),cntr, (ft_strlen(str) + cntr +1));
	// exit(1);
	char *out;
	out = malloc((sizeof(char) * ft_strlen(str)) + cntr +1);
	if(!out)
		return "failed";
	while (str[++index])
	{
		if (str[index] == '|')
			add_spc(&index,&nindex,str,&out);
		if (str[index] == '<' &&  str[index +1] == '<')
			add_spc(&index,&nindex,str,&out);
		else if (str[index] == '<')
			add_spc(&index,&nindex,str,&out);
		if (str[index] == '>')
			add_spc(&index,&nindex,str,&out);
		out[++nindex] = str[index];
	}
	out[++nindex] = '\0';
	return (out);
}

void	add_spc(int *index, int *nindex, char *str,char **out)
{
	if (str[(*index) - 1] != ' ')
		(*out)[++(*nindex)] = ' ';
	(*out)[++(*nindex)] = str[(*index)];
	if (str[(*index) + 1] != ' ')
		(*out)[++(*nindex)] = ' ';
	(*index)++;
}