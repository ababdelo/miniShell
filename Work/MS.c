/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:47 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/11 22:29:32 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

int	word_cnt(char const *s, char del)
{
	int	index;
	int	count;

	index = -1;
	count = 0;
	while (s[++index] != '\0')
	{
		helper(&index, s);
		if(s[index] == del && s[index] != '\0')
			count++;
	}
	// printf("pipe_cnt: %d\n", count);
	return (count);
}

int	*sep_pos(char const *str, char sep, int cntr)
{
	
	int *pos;
	int index = -1;
	int pindex = -1;
	pos = malloc(sizeof(int) * (cntr+1));
	if (!pos)
		return NULL;
	while (str[++index])
	{
		helper(&index, str);
		if (str[index] == sep && str[index] != '\0')
			pos[++pindex] = index;
	}
	pos[++pindex] = index;
	// index =-1;
	// while(++index < cntr +1)
	// 	printf("sep_pos[%d] : %d\n", index, pos[index]);
	return pos;
}

size_t	ft_wrdlen(char const *str, char sep)
{
	int	index;

	index = 0;
	// printf("---------:%s\n", str);
	if (!str)
		return (0);
	while (str[index] && str[index] != sep)
	{
		helper(&index, str);
		if(str[index] != '\0')
			++index;
	}
	// printf("word_len: %d\n", index);
	return (index);
}

char **ft_split(char *str, char sep)
{
	int cntr;
	int *pos;
	char	**ret;
	int len = 0;
	int	wrd_len = -1;
	int str_index = -1;
	int pos_index = 0;
	int ret_index = 0;
	int index;
	cntr = word_cnt(str, sep);
	pos = sep_pos(str, sep, cntr);
	ret = malloc(sizeof(char*) * (cntr + 2));
	if (!ret)
		return NULL;
	cntr+=1;
	while (++str_index < cntr)
	{
		wrd_len = ft_wrdlen(&str[len], sep);
		len += wrd_len+1;
		ret[str_index] = malloc(sizeof(char) * wrd_len + 1);
		if (!ret[str_index])
			return NULL;
	}
	str_index = -1;
	index = -1;
	while (str[++str_index])
	{
		if (str_index < pos[pos_index])
			ret[ret_index][++index] = str[str_index];
		else
		{
			ret[ret_index][++index] = '\0';
			if(pos_index < cntr)
				pos_index++;
			if(ret_index < cntr)
				ret_index++;
			index = -1;
		}
	}
	ret[ret_index][++index] = '\0';
	// printf("here\n");
	ret[++ret_index] = NULL;
	free(pos);
	return ret;
}

int main(int ac, char **av, char **env)
{
	(void) env;
	(void) ac;
	ft_parser(av[1]);
	
	// if (ac == 2 )
	// 	ft_parser(av[1]);
	// else
	// 	printf("Enter specific argumments :)\n");
	
	// char *path = "/bin/cat";
	// char *new[] = {"/bin/cat",av[1],NULL};
	// 	// printf("%s %s\n",new[0],new[1]);
	// execve(path,new,env);
	// perror("error\n");
	
}

