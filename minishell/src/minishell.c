/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:04:50 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:47:23 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != 1)
		return (1);
	init_st();
	if (malloc_envp(envp))
		return (1);
	init_signal();
	while (1)
	{
		g_st.input = readline(C_YELLOW "minishell: " C_RESET);
		if (!g_st.input)
			break ;
		if (*g_st.input)
			add_history(g_st.input);
		if (!(lexer() || parser() || get_split_path() || get_nb_cmd()
				|| prepare_st_cmd() || cmds_valid()))
			g_st.err = exec_cmd();
		else
			g_st.err = 1;
		free_all();
	}
	ft_free_2d(&g_st.envp);
	ft_printf("exit\n");
	return (0);
}

void	clean_exit(int state)
{
	free_all();
	ft_free_2d(&g_st.envp);
	exit(state);
}
