/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:30:53 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/05 14:01:37 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_name(char *str)
{
	int		i;
	char	*res;

	i = 1;
	if (ft_isalpha(str[i++]))
		while (ft_isalnum(str[i]))
			i++;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (res);
	res = ft_strlcpy(res, str, i);
	res[i] = 0;
	return (res);
}

char	*get_var_value(char *str)
{
	char	*res;

	if (ft_strlen(str) < 2)
		return (ft_strdup(str));
	if (!ft_strcmp(str, "$?"))
		return (ft_itoa(g_st.err));
	res = ft_strdup(ft_getenv(str + 1));
	if (!res)
		return (ft_strdup(""));
	return (res);
}

char	*copy_var(char *str, char	*var_name, char	*var_value, int sep)
{
	char	*res;

	res = calloc(sep + ft_strlen(var_value)
			+ ft_strlen(str + sep + ft_strlen(var_name)) + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, str, sep);
	ft_strcpy(res + sep, var_value);
	ft_strcpy(res + sep + ft_strlen(var_value),
		str + sep + ft_strlen(var_name));
	return (res);
}

char	*expand_var(char *str, int sep)
{
	char	*res;
	char	*var_name;
	char	*var_value;

	var_name = get_var_name(str + sep);
	var_value = get_var_value(var_name);
	if (!var_value)
	{
		free(var_name);
		return (0);
	}
	res = copy_var(str, var_name, var_value, sep);
	free(var_name);
	free(var_value);
	return (res);
}

char	*exp_vars(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = expand_var(str, i);
			free(str);
			str = tmp;
			i--;
		}
		i++;
	}
	return (str);
}
