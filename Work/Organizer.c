/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:15:23 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/11 15:04:20 by ababdelo         ###   ########.fr       */
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
	if (ret < 0)
	{
		cntr += ret * -1;
		ret = herd_cntr(str);
		if (ret == -1)
			return "herd_cntr";
		cntr += ret;	
	}
	else
		cntr += ret;
	ret = rredir_cntr(str);
	if (ret < 0)
	{
		cntr += ret * -1;
		ret = append_cntr(str);
		if (ret == -1)
			return "append_cntr";
		cntr += ret;	
	}
	else
		cntr += ret;
	return (organizer(-1, -1, cntr, str));
}

char *organizer(int index, int nindex, int cntr, char *str)
{
	char *out;
	out = malloc((sizeof(char) * ft_strlen(str)) + cntr +1);
	if(!out)
		return "failed";
	while (str[++index])
	{
		if (str[index] == '|')
			add_spc(&index,&nindex,str,&out);
		if (str[index] == '<' &&  str[index +1] == '<')
			add_spc2(&index,&nindex,str,&out);
		else if (str[index] == '<')
			add_spc(&index,&nindex,str,&out);
		if (str[index] == '>' && str[index + 1] == '>')
			add_spc2(&index,&nindex,str,&out);
		else if (str[index] == '>')
			add_spc(&index,&nindex,str,&out);
		else if(str[index] == '\'')
		{
			if (add_spc3(&index, &nindex, str, &out) == -1)
				return "Inclosed single quote";
		}
		else if(str[index] == '"')
		{
			if (add_spc4(&index, &nindex, str, &out) == -1)
				return "Inclosed double quote";
		}
		if(str[index] == '\0')
			break;
		if (str[index] == '|' || str[index] == '<'
			|| str[index] == '>' || str[index] == '"'
			|| str[index] == '\'')
			index--;
		else
			out[++nindex] = str[index];
	}
	out[++nindex] = '\0';
	return (out);
}

int	add_spc4(int *index, int *nindex, char *str,char **out)
{
	(*out)[++(*nindex)] = '"';
	while (str[++(*index)] != '"' && str[(*index)])
		(*out)[++(*nindex)] = str[(*index)];
	if(str[(*index)] == '\0')
		return -1;
	(*out)[++(*nindex)] = '"';
	(*index)++;
	return 0;
}

int	add_spc3(int *index, int *nindex, char *str,char **out)
{
	(*out)[++(*nindex)] = '\'';
	while (str[++(*index)] != '\'' && str[(*index)])
		(*out)[++(*nindex)] = str[(*index)];
	if(str[(*index)] == '\0')
		return -1;
	(*out)[++(*nindex)] = '\'';
	(*index)++;
	return 0;
}

void	add_spc2(int *index, int *nindex, char *str,char **out)
{
	if (str[(*index) - 1] != ' ')
		(*out)[++(*nindex)] = ' ';
	(*out)[++(*nindex)] = str[(*index)];
	(*out)[++(*nindex)] = str[(*index)];
	if (str[(*index) + 2] != ' ')
		(*out)[++(*nindex)] = ' ';
	(*index)+= 2;
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