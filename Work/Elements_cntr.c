/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Elements_cntr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:15:16 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/10 20:46:01 by ababdelo         ###   ########.fr       */
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
	// printf("pipe_cntr %d\n", cntr);
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
				return cntr * -1;
			if (str[index + 1] != '<')
				cntr++;
			else
				return cntr * -1;
		}
	}
	// printf("lredir_cntr %d\n", cntr);
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
	// printf("rredir_cntr %d\n", cntr);
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
				if(str[index + 2] != '<' && str[index + 2] != '>')
					cntr++;
				else
					return (-1);
			}
			else if(str[index + 1] == '>')
				return (-1);
		}
	}
	// printf("herd_cntr %d\n", cntr);
	return cntr;
}

int append_cntr(char *str)
{
	int index = -1;
	int cntr = 0;
	if(str[++index] == '>')
	{
		if(str[++index] != '>')
			cntr++;
		else
			return (-1);
	}
	while (str[++index])
	{		
		if(str[index] == '>' )
		{
			if(str[index + 1] == '>')
			{
				if(str[index - 1] != '>')
					cntr++;
				else
					return (-1);
				if(str[index + 2] != '>' && str[index + 2] != '<')
					cntr++;
				else
					return (-1);
			}
			else if(str[index + 1] == '<')
				return (-1);
		}
	}
	// printf("append_cntr %d\n", cntr);
	return cntr;
}