/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:29:46 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 15:36:58 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int *len)
{
	int	index;

	index = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
	}
	while (str && str[index] != '\0')
	{
		ft_putchar(str[index], len);
		index++;
	}
}
