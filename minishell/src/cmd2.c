/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:02:59 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 12:02:24 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_redir(t_list *tmp, int n_cmd, int index_redir)
{
	if (tmp->next && get_type(tmp->next) == WORD)
	{
		g_st.list_cmd[n_cmd].list_redir[index_redir].index
			= get_redir2(tmp);
		g_st.list_cmd[n_cmd].list_redir[index_redir].filename
			= ft_strdup(get_str(tmp->next));
	}
	else
		return (0);
	return (2);
}

int	cmd_word(t_list *tmp, int n_cmd)
{
	int		i;
	char	*word;
	char	**arr;

	i = 0;
	while (tmp && get_type(tmp) == WORD)
	{
		word = ft_strdup(get_str(tmp));
		if (!word)
			return (-err(ENOMEM));
		arr = add_arg(word, g_st.list_cmd[n_cmd].args);
		if (!arr)
			return (-err(ENOMEM));
		g_st.list_cmd[n_cmd].args = arr;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	cmd_pipe(int *n_cmd)
{
	g_st.list_cmd[*n_cmd].pipe_out = 1;
	(*n_cmd)++;
	g_st.list_cmd[*n_cmd].pipe_in = 1;
	return (1);
}

int	cmds_valid(void)
{
	int	i;

	i = 0;
	while (i < g_st.nb_cmd)
	{
		if (!g_st.list_cmd[i].args)
			return (1);
		i++;
	}
	return (0);
}
