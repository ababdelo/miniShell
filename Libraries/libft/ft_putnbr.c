/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:47:47 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 18:48:31 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr, int *len)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			ft_putstr("-2147483648", len);
		else
		{
			ft_putchar('-', len);
			ft_putnbr(-nbr, len);
		}
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar((nbr + '0'), len);
	else
	{
		ft_putnbr((nbr / 10), len);
		ft_putnbr((nbr % 10), len);
	}
}
