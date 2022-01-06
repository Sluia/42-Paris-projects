/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:14:40 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 14:53:49 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handling_redirection(int i)
{
	int	j;

	j = 0;
	while (j < g_st.list_cmd[i].nb_redir)
	{
		if (g_st.list_cmd[i].list_redir[j].index == 3 && heredoc(i, j))
			return (1);
		else if (g_st.list_cmd[i].list_redir[j].index == 1
			|| g_st.list_cmd[i].list_redir[j].index == 3)
		{
			if (handling_redirection_1(i, j))
				return (err(EPERM));
		}
		else
		{
			if (handling_redirection_2_4(i, j))
				return (err(EPERM));
		}
		j++;
	}
	return (0);
}

int	handling_redirection_1(int i, int j)
{
	g_st.list_cmd[i].list_redir[j].fd
		= open(g_st.list_cmd[i].list_redir[j].filename, O_RDONLY);
	if (g_st.list_cmd[i].list_redir[j].fd == -1)
		return (1);
	if (dup2(g_st.list_cmd[i].list_redir[j].fd, STDIN_FILENO) == -1)
		return (1);
	close(g_st.list_cmd[i].list_redir[j].fd);
	return (0);
}

int	handling_redirection_2_4(int i, int j)
{
	if (g_st.list_cmd[i].list_redir[j].index == 2)
		g_st.list_cmd[i].list_redir[j].fd
			= open(g_st.list_cmd[i].list_redir[j].filename, O_WRONLY | O_CREAT
				| O_TRUNC, 0644);
	else
		g_st.list_cmd[i].list_redir[j].fd
			= open(g_st.list_cmd[i].list_redir[j].filename, O_WRONLY | O_CREAT
				| O_APPEND, 0644);
	if (g_st.list_cmd[i].list_redir[j].fd == -1)
		return (1);
	if (dup2(g_st.list_cmd[i].list_redir[j].fd, STDOUT_FILENO) == -1)
		return (1);
	close(g_st.list_cmd[i].list_redir[j].fd);
	return (0);
}
