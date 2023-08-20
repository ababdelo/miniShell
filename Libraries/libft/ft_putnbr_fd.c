/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:28:31 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:28:38 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	j;

	j = (long long)n;
	if (j < 0)
	{
		ft_putchar_fd('-', fd);
		j *= -1;
	}
	if (j < 10)
		ft_putchar_fd(j + '0', fd);
	if (j >= 10)
	{
		ft_putnbr_fd(j / 10, fd);
		ft_putchar_fd((j % 10) + '0', fd);
	}
}
