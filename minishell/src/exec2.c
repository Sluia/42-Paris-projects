/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:40:52 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 15:09:12 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_one_cmd(int i)
{
	if (handling_redirection(i) || handling_pipes(i))
		clean_exit(1);
	if (is_builtin(g_st.list_cmd[i].args))
	{
		if (exec_builtin(g_st.list_cmd[i].args) | close_pipe_fd())
			clean_exit(1);
		clean_exit(0);
	}
	else
	{
		g_st.list_cmd[i].path_cmd
			= get_cmd_path(g_st.split_path, g_st.list_cmd[i].args[0]);
		if (!g_st.list_cmd[i].path_cmd)
			clean_exit(err(ENOENT));
		if (close_pipe_fd())
			clean_exit(1);
		if (execve(g_st.list_cmd[i].path_cmd,
				g_st.list_cmd[i].args, g_st.envp) == -1)
			clean_exit(err(ENOENT));
	}
}

int	exec_child(int i)
{
	g_st.list_cmd[i].pid = fork();
	if (g_st.list_cmd[i].pid == -1)
		return (err(ECHILD));
	if (!g_st.list_cmd[i].pid)
		exec_one_cmd(i);
	return (0);
}

int	close_pipe_fd(void)
{
	int	i;

	if (g_st.nb_cmd > 1)
	{
		i = 0;
		while (i < g_st.nb_cmd - 1)
		{
			if (close(g_st.fd_pipes[i][0]) || close(g_st.fd_pipes[i][1]))
				err(EBADF);
			i++;
		}
	}
	return (0);
}

int	wait_end_exec(void)
{
	int	i;
	int	status;
	int	ret;

	i = 0;
	ret = 0;
	while (i < g_st.nb_cmd)
	{
		if (!(g_st.nb_cmd == 1 && is_builtin(g_st.list_cmd[i].args)))
		{
			if ((waitpid(g_st.list_cmd[i].pid, &status, 0) == -1))
				ret = err(ECHILD);
			ret = WEXITSTATUS(status);
		}
		i++;
	}
	return (ret);
}
