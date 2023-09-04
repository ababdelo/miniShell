/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:03:37 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/04 16:09:32 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

int				create_heredoc(t_lexer *heredoc, bool quotes,
					t_tools *tools, char *file_name);
int				ft_heredoc(t_tools *tools, t_lexer *heredoc, char *file_name);
char			*generate_heredoc_filename(void);
int				send_heredoc(t_tools *tools, t_simple_cmds *cmd);
int				find_cmd(t_simple_cmds *cmd, t_tools *tools);
void			handle_cmd(t_simple_cmds *cmd, t_tools *tools);
void			dup_cmd(t_simple_cmds *cmd, t_tools *tools,
					int end[2], int fd_in);
void			single_cmd(t_simple_cmds *cmd, t_tools *tools);
t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
int				pipe_wait(int *pid, int amount);
int				ft_fork(t_tools *tools, int end[2], int fd_in,
					t_simple_cmds *cmd);
int				check_fd_heredoc(t_tools *tools, int end[2],
					t_simple_cmds *cmd);
int				executor(t_tools *tools);
int				check_append_outfile(t_lexer *redirections);
int				handle_infile(char *file);
int				handle_outfile(t_lexer *redirection);
int				check_redirections(t_simple_cmds *cmd);

#endif
