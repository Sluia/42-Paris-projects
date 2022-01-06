/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:54:22 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/28 19:51:45 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_st(void)
{
	g_st.input = NULL;
	g_st.split_path = NULL;
	g_st.fd_pipes = NULL;
	g_st.envp = 0;
	g_st.fd_pipes = 0;
	g_st.err = 0;
	g_st.words = 0;
	g_st.tokens = 0;
	g_st.list_cmd = 0;
}

int	malloc_envp(char **envp)
{
	int	i;
	int	j;
	int	envp_len;

	envp_len = ft_arrlen(envp);
	g_st.envp = malloc((envp_len + 1) * sizeof(char *));
	if (!g_st.envp)
		return (err(ENOMEM));
	i = 0;
	j = 0;
	while (i < envp_len)
	{
		g_st.envp[i] = ft_strdup(envp[i]);
		if (!g_st.envp[i])
		{
			while (j <= i)
				free(g_st.envp[j++]);
			return (err(ENOMEM));
		}
		i++;
	}
	g_st.envp[envp_len] = 0;
	return (0);
}
