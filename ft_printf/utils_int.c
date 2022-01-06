/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:25:52 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:32:08 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_condition(t_parser *pars, char *str, char *pcs_str)
{
	if (pars->left_align)
		check_cdtleft(pars, str, pcs_str);
	else
		check_cdtright(pars, str, pcs_str);
}

void	check_cdtleft(t_parser *pars, char *str, char *pcs_str)
{
	if (pars->isneg)
	{
		str[0] = '-';
		ft_strcpy(&str[1], pcs_str, pars->precision);
	}
	else
		ft_strcpy(str, pcs_str, pars->precision);
}

void	check_cdtright(t_parser *pars, char *str, char *pcs_str)
{
	if (pars->isneg)
	{
		str[pars->width - pars->precision - 1] = '-';
		ft_strcpy(&str[pars->width - pars->precision], pcs_str,
				pars->precision);
		if (pars->fill_w0)
		{
			str[pars->width - pars->precision - 1] = '0';
			str[0] = '-';
		}
	}
	else
		ft_strcpy(&str[pars->width - pars->precision], pcs_str,
				pars->precision);
}

void	check_condition_uint(t_parser *pars, char *str, char *pcs_str)
{
	if (pars->left_align)
		ft_strcpy(str, pcs_str, pars->precision);
	else
		ft_strcpy(&str[pars->width - pars->precision], pcs_str,
				pars->precision);
	str[pars->width] = '\0';
	ft_wrstr(str, 1, pars->width);
}

void	check_condition_hex(t_parser *pars, char *str, char *pcs_str)
{
	if (pars->left_align)
		ft_strcpy(str, pcs_str, pars->precision);
	else
		ft_strcpy(&str[pars->width - pars->precision], pcs_str,
				pars->precision);
	str[pars->width] = '\0';
	ft_wrstr(str, 1, pars->width);
}
