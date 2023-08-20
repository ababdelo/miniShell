/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:20:42 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/19 14:24:25 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_lenght(long long n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if (sign)
		i++;
	return (i);
}

char	*fill_arr(long long n, char *arr, int i, int sign)
{
	arr[i] = '\0';
	i--;
	if (n == 0)
	{
		arr[i] = '0';
		i--;
	}
	while (n > 0)
	{
		arr[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	if (sign)
	{
		arr[i] = '-';
		i++;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int			i;
	int			sign;
	char		*arr;
	long long	j;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		j = (long long)n * -1;
	}
	else
		j = (long long)n;
	i = count_lenght(j, sign);
	arr = malloc(i * sizeof(char) + 1);
	if (!arr)
		return (0);
	arr = fill_arr(j, arr, i, sign);
	return (arr);
}
