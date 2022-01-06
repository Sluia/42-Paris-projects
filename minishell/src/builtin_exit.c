/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:43:38 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 21:06:17 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **argv)
{
	int	argc;

	argc = ft_arrlen(argv);
	if (argc > 2)
		return (err(EPERM));
	if (g_st.nb_cmd == 1)
		ft_printf("exit\n");
	if (argc == 1)
		clean_exit(0);
	if (!ft_isnum(argv[1]))
	{
		err(EINVAL);
		clean_exit(255);
	}
	else
		clean_exit(ft_atoi(argv[1]) % 256);
	return (0);
}
