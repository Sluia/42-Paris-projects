/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:37:34 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 17:17:30 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

static void	initparams(t_params *params)
{
	params->flags_field = 0;
	params->width_field = 0;
	params->precision_field = 0;
	params->length_field = 0;
	params->nb_chars_var = 0;
	params->sign = 0;
	params->local_count = 0;
}

const char	*conversion(const char *format, t_params *params, va_list ap)
{
	if (*format == '%')
		putpctformatted(params);
	else if (*format == 'c')
		putcharformatted(va_arg(ap, int), params);
	else if (*format == 's')
		putstring(va_arg(ap, char *), params);
	else if ((*format == 'i') | (*format == 'd'))
		putint(va_arg(ap, int), params);
	else if (*format == 'u')
		putint(va_arg(ap, unsigned int), params);
	else if (*format == 'x')
	{
		params->length_field |= HEXA_MIN;
		putint(va_arg(ap, unsigned int), params);
	}
	else if (*format == 'X')
	{
		params->length_field |= HEXA_MAJ;
		putint(va_arg(ap, unsigned int), params);
	}
	else if (*format == 'p')
		putpointer((unsigned long long int)va_arg(ap, void *), params);
	else
		return (format);
	return (++format);
}

void	readformat(const char *format, va_list ap, t_params *params)
{
	while (*format)
	{
		initparams(params);
		if (*format != '%')
		{
			putcharcount(*format, params);
			format++;
		}
		else
		{
			format++;
			format = flags(format, params);
			format = width(format, params, ap);
			format = precision(format, params, ap);
			format = length(format, params);
			format = conversion(format, params, ap);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_params	params;

	params.global_count = 0;
	va_start(ap, format);
	readformat(format, ap, &params);
	va_end(ap);
	return (params.global_count);
}
