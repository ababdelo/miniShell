/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:11:57 by ababdelo          #+#    #+#             */
/*   Updated: 2023/08/31 12:29:44 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

int	implement_tools(t_tools *tools);
int	reset_tools(t_tools *tools);
int	prepare_executor(t_tools *tools);
int	minishell_loop(t_tools *tools);
int	find_pwd(t_tools *tools);
char	*find_path(char **envp);
int	parse_envp(t_tools *tools);

#endif