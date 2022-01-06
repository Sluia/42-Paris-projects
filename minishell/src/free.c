/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:43:46 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 14:59:05 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lex(void *lex)
{
	if (lex)
	{
		ft_free_1d(&((t_lex *)lex)->str);
		free(lex);
	}
}

void	free_tokens(void)
{
	ft_lstclear(&g_st.tokens, free_lex);
}

void	free_words(void)
{
	ft_lstclear(&g_st.words, free_lex);
}

void	free_cmd(void)
{
	int	i;
	int	j;

	i = 0;
	if (g_st.list_cmd)
	{
		while (i < g_st.nb_cmd)
		{
			j = 0;
			while (j < g_st.list_cmd[i].nb_redir)
			{
				ft_free_1d(&g_st.list_cmd[i].list_redir[j].filename);
				j++;
			}
			free(g_st.list_cmd[i].list_redir);
			ft_free_1d(&g_st.list_cmd[i].path_cmd);
			ft_free_2d(&g_st.list_cmd[i].args);
			i++;
		}
		free(g_st.list_cmd);
		g_st.list_cmd = 0;
	}
}

void	free_pipes(void)
{
	int	i;

	i = 0;
	if (g_st.fd_pipes)
	{
		while (i < g_st.nb_cmd - 1)
		{
			if (g_st.fd_pipes[i])
			{
				free(g_st.fd_pipes[i]);
				g_st.fd_pipes[i] = 0;
			}
			i++;
		}
		free(g_st.fd_pipes);
		g_st.fd_pipes = 0;
	}
}
