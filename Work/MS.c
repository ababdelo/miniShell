/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:47 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/12 14:57:41 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"



int main(int ac, char **av, char **env)
{
	(void) env;
	(void) ac;
	t_splitval splitval;
	ft_parser(av[1], &splitval);
	
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

