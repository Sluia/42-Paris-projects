/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:03:38 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 13:06:37 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_split_path(void)
{
	size_t	i;

	i = 0;
	while (g_st.envp[i])
	{
		if (ft_strncmp(g_st.envp[i], "PATH=", 5) == 0)
		{
			g_st.split_path = ft_split(&g_st.envp[i][5], ':');
			if (!g_st.split_path)
				return (err(ENOMEM));
			if (join_path())
				return (1);
		}
		i++;
	}
	return (0);
}

int	exec_onebuiltin(int i)
{
	int	res;

	g_st.clone_stdout = dup(STDOUT_FILENO);
	if (handling_redirection(i) || handling_pipes(i))
		return (1);
	res = exec_builtin(g_st.list_cmd[0].args);
	dup2(g_st.clone_stdout, STDOUT_FILENO);
	close(g_st.clone_stdout);
	return (res);
}

int	exec_cmd(void)
{
	int	i;

	i = 0;
	while (i < g_st.nb_cmd)
	{
		if (g_st.nb_cmd == 1 && is_builtin(g_st.list_cmd[i].args))
		{
			if (exec_onebuiltin(i))
				return (1);
		}
		else
		{
			if (exec_child(i))
				return (1);
		}
		i++;
	}
	close_pipe_fd();
	return (wait_end_exec());
}

char	*get_cmd_path(char **split, char *arg)
{
	char	*path;
	int		i;

	if (!split)
		return (0);
	if (!access(arg, F_OK | X_OK))
		return (arg);
	i = 0;
	while (split[i])
	{
		path = ft_strjoin(split[i], arg);
		if (!path)
			return (NULL);
		if (!access(path, F_OK | X_OK))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

int	handling_pipes(int i)
{
	if (g_st.list_cmd[i].pipe_in)
	{
		if (dup2(g_st.fd_pipes[i - 1][0], STDIN_FILENO) == -1)
			return (err(ENOMEM));
	}
	if (g_st.list_cmd[i].pipe_out)
	{
		if (dup2(g_st.fd_pipes[i][1], STDOUT_FILENO) == -1)
			return (err(ENOMEM));
	}
	return (0);
}
