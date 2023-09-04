/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:29:23 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/04 11:29:45 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (ft_is_wide_space(str[i + j]))
		j++;
	return (j);
}
