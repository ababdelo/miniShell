/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 09:49:41 by elel-yak          #+#    #+#             */
/*   Updated: 2023/09/03 12:29:30 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

//builtins

int	(*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);

void	change_path(t_tools *tools);

int		ft_echo(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_cd(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_pwd(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_export(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_unset(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_env(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_exit(t_tools *tools, t_simple_cmds *simple_cmd);

int		ft_continue(t_tools *tools, t_simple_cmds *simple_cmd);

size_t	equal_sign(char *str);
int		check_valid_identifier(char c);

#endif
