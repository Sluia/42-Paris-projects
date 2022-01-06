/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:43:02 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 17:17:43 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

const char	*flags(const char *format, t_params *params)
{
	while (*format)
	{
		if (*format == '-')
			params->flags_field |= MINUS;
		else if (*format == '+')
			params->flags_field |= PLUS;
		else if (*format == ' ')
			params->flags_field |= SPACES;
		else if (*format == '0')
			params->flags_field |= ZERO;
		else if (*format == '\'')
			params->flags_field |= PLUS;
		else if (*format == '#')
			params->flags_field |= HASH;
		else
			break ;
		format++;
	}
	return (format);
}

const char	*width(const char *format, t_params *params, va_list ap)
{
	int	wid;

	if (*format == '*')
	{
		wid = va_arg(ap, int);
		if (wid < 0)
		{
			params->width_field = -wid;
			params->flags_field |= MINUS;
		}
		else
			params->width_field = wid;
		format++;
		params->flags_field |= WIDTH;
	}
	else
	{
		params->width_field = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
		params->flags_field |= WIDTH;
	}
	return (format);
}

const char	*precision(const char *format, t_params *params, va_list ap)
{
	int	prec;

	if (*format == '.')
		format++;
	else
		return (format);
	if (*format == '*')
	{
		prec = va_arg(ap, int);
		if (prec >= 0)
		{
			params->flags_field |= PRECISION;
			params->precision_field = prec;
		}
		format++;
	}
	else
	{
		params->flags_field |= PRECISION;
		params->precision_field = (unsigned int)ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

const char	*length(const char *format, t_params *params)
{
	if (*format == 'l')
	{
		params->length_field = LONG;
		format++;
		if (*format == 'l')
		{
			params->length_field = LONG_LONG;
			format++;
		}
	}
	if (*format == 'h')
	{
		params->length_field = SHORT;
		format++;
		if (*format == 'h')
		{
			params->length_field = CHAR;
			format++;
		}
	}
	return (format);
}
