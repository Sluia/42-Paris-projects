/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:29:40 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:30:13 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		format(t_parser *pars, va_list args)
{
	int nb_cprinted;

	if (pars->type == PERCENTAGE)
		nb_cprinted = format_char(pars, '%');
	else if (pars->type == CHAR)
		nb_cprinted = format_char(pars, va_arg(args, int));
	else if (pars->type == STRING)
		nb_cprinted = format_str(pars, va_arg(args, char *));
	else if (pars->type == INT)
		nb_cprinted = format_int(pars, va_arg(args, int));
	else if (pars->type == UNSIGNED_INT)
		nb_cprinted = format_uint(pars, va_arg(args, unsigned int));
	else if (pars->type == HEX || pars->type == HEX_CAPS)
		nb_cprinted = format_hex(pars, va_arg(args, unsigned int));
	else if (pars->type == POINTER)
		nb_cprinted = format_pointer(pars, va_arg(args, unsigned long));
	else
		return (0);
	return (nb_cprinted);
}

int		parse_spec(const char *cvers, va_list args)
{
	t_parser	pars;
	int			i;

	init_parser(&pars);
	i = 0;
	while (cvers[i] == '-' || cvers[i] == '0')
	{
		set_flags(&pars, cvers[i]);
		i++;
	}
	while (ft_isdigit(cvers[i]) || cvers[i] == '*')
	{
		set_width(&pars, cvers[i], args);
		i++;
	}
	while (ft_isdigit(cvers[i]) || cvers[i] == '*' || cvers[i] == '.')
	{
		set_precision(&pars, cvers[i], args);
		i++;
	}
	pars.type = set_type(cvers[i]);
	return (format(&pars, args));
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			char_written;
	int			i;

	char_written = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char_written += parse_spec(&format[i + 1], args);
			i += index_spec(&format[i + 1]) + 2;
		}
		else
		{
			ft_wrchar(format[i], 1);
			i++;
			char_written++;
		}
	}
	va_end(args);
	return (char_written);
}
