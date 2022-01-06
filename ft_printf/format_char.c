/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:15:03 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:15:32 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	format_char(t_parser *pars, int c)
{
	char *str;

	if (pars->width == 0)
		pars->width = 1;
	str = malloc(sizeof(char) * (pars->width + 1));
	if (str == NULL)
		return (0);
	str = fill_sp0(str, pars);
	if (pars->left_align == 1)
		str[0] = c;
	else
		str[pars->width - 1] = c;
	str[pars->width] = '\0';
	ft_wrstr(str, 1, pars->width);
	free(str);
	return (pars->width);
}
