/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:23:48 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 15:35:48 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long nbr, char *base, int *len)
{
	size_t	sizebase;

	sizebase = ft_strlen(base);
	if (nbr / sizebase > 0)
		ft_putnbr_base((nbr / sizebase), base, len);
	ft_putchar(base[nbr % sizebase], len);
}
