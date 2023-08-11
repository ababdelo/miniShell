/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:47 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/11 17:28:28 by ababdelo         ###   ########.fr       */
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
		if(s[index] == del)
			count++;
	}
	// printf("------------ [%d] ------------\n", count+1);
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
		if (str[index] == sep)
			pos[++pindex] = index;
	}
	pos[++pindex] = -1;
	return pos;
}

size_t	ft_wrdlen(char const *str, char sep)
{
	int	index;

	index = -1;
	if (!str)
		return (0);
	while (str[++index] && str[index] != sep)
		helper(&index, str);
	return (index);
}

char **ft_splite(char *str, char sep)
{
	int cntr;
	int *pos;
	char	**ret;
	int	wrd_len = 0;
	int str_index = -1;
	int pos_index = 0;
	int ret_index = -1;
	int index = -1;
	cntr = word_cnt(str, sep);
	pos = sep_pos(str, sep, cntr);
	ret = malloc(sizeof(char*) * (cntr + 1) + 1);
	if (!ret)
		return NULL;
	while (pos[++str_index] != -1)
	{
		wrd_len = ft_wrdlen(&str[wrd_len], sep);
		ret[str_index] = malloc(sizeof(char) * wrd_len + 1);
		if (!ret[str_index])
			return NULL;
	}
	str_index = -1;
	while (str[++str_index])
	{
		if (str_index < pos[pos_index])
			ret[ret_index][++index] = str[str_index];
		else
		{	
			pos_index++;
			ret_index++;
			index = -1;
		}
	}
	free(pos);
	// 	printf("pos[%d] : %d\n", index, pos[index]);
	return ret;
}
int main(int ac, char **av, char **env)
{
	printf("old line: %s\n",av[1]);
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

