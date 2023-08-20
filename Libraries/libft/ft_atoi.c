/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:19:20 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:23:08 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;
	int	i;

	i = 0;
	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
		if (i == 10 && str[i] && sign == -1)
			return (0);
		else if (i == 10 && str[i])
			return (-1);
	}
	return (ret * sign);
}
