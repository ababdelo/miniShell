/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MS.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:23:47 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/10 18:20:16 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MS.h"

int main(int ac, char **av, char **env)
{
	(void) env;
	if (ac == 2 )
	{
		printf("%s\n", str_norm(av[1]));
	}
	else
		printf("Enter specific argumments :)\n");
}