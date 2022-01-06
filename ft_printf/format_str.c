/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:28:58 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:29:29 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	format_str(t_parser *pars, char *arg_str)
{
	char *str;

	if (arg_str == NULL)
		arg_str = "(null)";
	if (pars->precision < 0 || pars->precision > (int)ft_strlen(arg_str))
		pars->precision = ft_strlen(arg_str);
	if (pars->width < pars->precision)
		pars->width = pars->precision;
	str = malloc(sizeof(char) * (pars->width + 1));
	if (str == NULL)
		return (0);
	str = fill_sp0(str, pars);
	if (pars->left_align)
		ft_strcpy(str, arg_str, pars->precision);
	else
		ft_strcpy(&str[pars->width - pars->precision],
				arg_str, pars->precision);
	str[pars->width] = '\0';
	ft_wrstr(str, 1, pars->width);
	free(str);
	return (pars->width);
}
