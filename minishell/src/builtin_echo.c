/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:50:51 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 01:53:04 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **argv)
{
	int	no_lr;
	int	i;
	int	argc;

	i = 1;
	argc = ft_arrlen(argv);
	no_lr = 0;
	if (argc > 1 && !ft_strcmp(argv[1], "-n"))
		no_lr = 1;
	while (i < argc)
	{
		if (!(i == 1 && argv[1][0] == '-'))
		{
			ft_printf("%s", argv[i]);
			if (i != argc - 1)
				ft_printf(" ");
		}
		i++;
	}
	if (!(no_lr || argc == 1 || (argc == 2 && argv[1][0] == '-')))
		ft_printf("\n");
	return (0);
}
