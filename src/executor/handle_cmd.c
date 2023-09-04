/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:32:10 by ababdelo          #+#    #+#             */
/*   Updated: 2023/09/03 13:08:36 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = ft_re_split_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, tools->envp);
	while (tools->paths[i])
	{
		mycmd = ft_strjoin(tools->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->str, tools->envp);
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

void	handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(tools, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, tools);
	exit(exit_code);
}

void	dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, tools);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, tools);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, tools);
}

void	single_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	pid;
	int	status;

	tools->simple_cmds = call_expander(tools, tools->simple_cmds);
	if (cmd->builtin == ft_cd || cmd->builtin == ft_exit
		|| cmd->builtin == ft_export || cmd->builtin == ft_unset)
	{
		g_global.error_num = cmd->builtin(tools, cmd);
		return ;
	}
	send_heredoc(tools, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, tools);
	if (pid == 0)
		handle_cmd(cmd, tools);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}
