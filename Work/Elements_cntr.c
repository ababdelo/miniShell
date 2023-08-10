/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_cntr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:15:16 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/10 18:20:40 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

int pipe_cntr(char *str)
{
	int index = -1;
	int cntr = 0;
	while (str[++index])
	{
		if (str[index] == '|')
		{
			if (str[index - 1] != '|')
				cntr++;
			else
				return -1;
			if (str[index + 1] != '|')
				cntr++;
			else
				return -1;
		}
	}
	return cntr;
}

int lredir_cntr(char *str)
{
	int index = -1;
	int cntr = 0;
	while (str[++index])
	{
		if (str[index] == '<')
		{
			if (str[index - 1] != '<')
				cntr++;
			else
				return -1;
			if (str[index + 1] != '<')
				cntr++;
			else
				return -1;
		}
	}
	return cntr;
}

int rredir_cntr(char *str)
{
	int index = -1;
	int cntr = 0;
	
	while (str[++index])
	{
		if (str[index] == '>')
		{
			if (str[index - 1] != '>')
				cntr++;
			else
				return -1;
			if (str[index + 1] != '>')
				cntr++;
			else
				return -1;
		}
	}
	return cntr;
}

int herd_cntr(char *str)
{
	int index = -1;
	int cntr = 0;
	if(str[++index] == '<')
	{
		if(str[++index] != '<')
			cntr++;
		else
			return (-1);
	}
	while (str[++index])
	{		
		if(str[index] == '<' )
		{
			if(str[index + 1] == '<')
			{
				if(str[index - 1] != '<')
					cntr++;
				else
					return (-1);
				if(str[index + 2] != '<')
					cntr++;
				else
					return (-1);
			}
		}
	}
	return cntr;
}