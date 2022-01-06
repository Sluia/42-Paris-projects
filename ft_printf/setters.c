/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:30:27 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:30:49 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	init_parser(t_parser *pars)
{
	pars->type = 0;
	pars->left_align = 0;
	pars->fill_w0 = 0;
	pars->width = 0;
	pars->precision = -1;
	pars->isneg = 0;
}

void	set_flags(t_parser *pars, char c)
{
	if (pars->left_align == 0 && c == '0')
		pars->fill_w0 = 1;
	else
	{
		pars->left_align = 1;
		pars->fill_w0 = 0;
	}
}

void	set_width(t_parser *pars, char c, va_list args)
{
	if (c == '*')
	{
		pars->width = va_arg(args, int);
		if (pars->width < 0)
		{
			pars->width *= -1;
			set_flags(pars, '-');
		}
	}
	else
		pars->width = (pars->width * 10) + c - 48;
}

void	set_precision(t_parser *pars, char c, va_list args)
{
	if (c == '.')
		pars->precision = 0;
	else if (c == '*')
		pars->precision = va_arg(args, int);
	else
		pars->precision = (pars->precision * 10) + c - 48;
}

t_type	set_type(char c)
{
	t_type en;

	en = 0;
	if (c == 'd' || c == 'i')
		en = INT;
	else if (c == 'c')
		en = CHAR;
	else if (c == 's')
		en = STRING;
	else if (c == 'p')
		en = POINTER;
	else if (c == 'u')
		en = UNSIGNED_INT;
	else if (c == 'x')
		en = HEX;
	else if (c == 'X')
		en = HEX_CAPS;
	else if (c == '%')
		en = PERCENTAGE;
	return (en);
}
