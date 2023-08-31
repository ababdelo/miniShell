/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:52:09 by elel-yak          #+#    #+#             */
/*   Updated: 2023/08/21 17:52:10 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_pwd(t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->envp[i])
	{
		if (!ft_strncmp(tools->envp[i], "PWD=", 4))
			tools->pwd = ft_substr(tools->envp[i],
					4, ft_strlen(tools->envp[i]) - 4);
		if (!ft_strncmp(tools->envp[i], "OLDPWD=", 7))
			tools->old_pwd = ft_substr(tools->envp[i],
					7, ft_strlen(tools->envp[i]) - 7);
		i++;
	}
	return (1);
}

char	*find_path(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
		i++;
	}
	return (ft_strdup("\0"));
}

int	parse_envp(t_tools *tools)
{
	char	*path_from_envp;
	int		i;
	char	*tmp;

	path_from_envp = find_path(tools->envp);
	tools->paths = ft_split(path_from_envp, ':');
	free(path_from_envp);
	i = 0;
	while (tools->paths[i])
	{
		if (ft_strncmp(&tools->paths[i][ft_strlen(tools->paths[i]) - 1],
			"/", 1) != 0)
		{
			tmp = ft_strjoin(tools->paths[i], "/");
			free(tools->paths[i]);
			tools->paths[i] = tmp;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
