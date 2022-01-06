/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:23:46 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:25:42 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*fill_sp0(char *str, t_parser *pars)
{
	int i;

	i = 0;
	while (i < pars->width)
	{
		if (pars->fill_w0 == 1)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	return (str);
}

void	memfree(int nb, ...)
{
	int		i;
	va_list	args;

	va_start(args, nb);
	i = 0;
	while (i < nb)
	{
		free(va_arg(args, char *));
		i++;
	}
	va_end(args);
}

int		index_spec(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 'i' || str[i] == 'c' || str[i] == 's'
		|| str[i] == 'p' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
		|| str[i] == '%')
		{
			return (i);
		}
		i++;
	}
	return (0);
}

char	*rev_arr(char *str, int nb_len)
{
	char	rev[nb_len];
	int		i;

	i = 0;
	while (i < nb_len)
	{
		rev[i] = str[nb_len - i - 1];
		i++;
	}
	i = 0;
	while (i < nb_len)
	{
		str[i] = rev[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
