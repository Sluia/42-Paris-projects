/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:51:34 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/28 20:08:36 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **argv)
{
	int	i;
	int	argc;

	i = 0;
	argc = ft_arrlen(argv);
	if (argc != 1)
		return (err(EPERM));
	while (g_st.envp[i])
		ft_printf("%s\n", g_st.envp[i++]);
	return (0);
}

char	**copy_and_sort(void)
{
	char	**res;
	char	*tmp;
	int		i;
	int		envp_len;

	i = 0;
	envp_len = ft_arrlen(g_st.envp);
	res = calloc(envp_len + 1, sizeof(char *));
	if (!res)
		return (res);
	ft_memcpy(res, g_st.envp, envp_len * sizeof(char *));
	while (i < envp_len - 1)
	{
		if (ft_strcmp(res[i], res[i + 1]) > 0)
		{
			tmp = res[i];
			res[i] = res[i + 1];
			res[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (res);
}

void	ft_display_line(char *str)
{
	int	i;

	i = 0;
	ft_printf("%s", "declare -x ");
	while (str[i] && str[i] != '=')
		ft_printf("%c", str[i++]);
	if (!str[i])
	{
		ft_printf("\n");
		return ;
	}
	ft_printf("=\"");
	ft_printf("%s", str + i + 1);
	ft_printf("\"\n");
}

int	ft_export_display(void)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = copy_and_sort();
	if (!tmp)
		return (err(ENOMEM));
	while (tmp[i])
		ft_display_line(tmp[i++]);
	free(tmp);
	return (0);
}
