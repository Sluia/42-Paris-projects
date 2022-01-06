/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:30:21 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 19:00:27 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_nbredir(int n_cmd, t_list *tmp)
{
	if (g_st.list_cmd[n_cmd].nb_redir == -1)
	{
		g_st.list_cmd[n_cmd].nb_redir = get_nbredir(tmp);
		if (g_st.list_cmd[n_cmd].nb_redir > 0)
		{
			g_st.list_cmd[n_cmd].list_redir
				= ft_calloc(g_st.list_cmd[n_cmd].nb_redir, sizeof(t_redir));
			if (!g_st.list_cmd[n_cmd].list_redir)
				return (1);
		}
	}
	return (0);
}

int	prepare_loop(int *n_cmd, t_list *tmp, int *index_redir)
{
	int	ret;

	if (get_type(tmp) == REDIR)
	{
		ret = cmd_redir(tmp, *n_cmd, *index_redir);
		(*index_redir)++;
	}
	if (get_type(tmp) == WORD)
		ret = cmd_word(tmp, *n_cmd);
	if (get_type(tmp) == PIPE)
	{
		ret = cmd_pipe(n_cmd);
		*index_redir = 0;
	}
	return (ret);
}

int	prepare_st_cmd(void)
{
	t_list	*tmp;
	int		n_cmd;
	int		mov;
	int		index_redir;

	init_cmd();
	init_pipes();
	tmp = g_st.words;
	n_cmd = 0;
	mov = 0;
	index_redir = 0;
	while (tmp)
	{
		if (check_nbredir(n_cmd, tmp))
			return (err(ENOMEM));
		mov = prepare_loop(&n_cmd, tmp, &index_redir);
		if (!mov)
			return (err(EPERM));
		if (mov < 0)
			return (1);
		tmp = ft_lstmove(tmp, mov);
	}
	return (0);
}

int	init_cmd(void)
{
	int	i;

	i = 0;
	g_st.list_cmd = ft_calloc(g_st.nb_cmd, sizeof(t_cmd));
	if (!g_st.list_cmd)
		return (err(ENOMEM));
	while (i < g_st.nb_cmd)
	{
		g_st.list_cmd[i].args = 0;
		g_st.list_cmd[i].list_redir = 0;
		g_st.list_cmd[i].nb_redir = -1;
		i++;
	}
	return (0);
}

int	init_pipes(void)
{
	int	i;

	if (g_st.nb_cmd > 1)
	{
		g_st.fd_pipes = ft_calloc(g_st.nb_cmd - 1, sizeof(int *));
		if (!g_st.fd_pipes)
			return (err(ENOMEM));
		i = 0;
		while (i < g_st.nb_cmd - 1)
		{
			g_st.fd_pipes[i] = ft_calloc(2, sizeof(int));
			if (!g_st.fd_pipes[i])
				return (err(ENOMEM));
			if (pipe(g_st.fd_pipes[i]))
				return (err(ENOMEM));
			i++;
		}
	}
	return (0);
}
