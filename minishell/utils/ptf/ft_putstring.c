/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:10:53 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 17:18:21 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	putcharcount(char c, t_params *params)
{
	write(1, &c, 1);
	params->global_count++;
	params->local_count++;
}

void	putcharformatted(unsigned char c, t_params *params)
{
	while (!(params->flags_field & MINUS)
		&& (params->local_count < params->width_field - 1))
		putcharcount(' ', params);
	putcharcount(c, params);
	while ((params->flags_field & MINUS)
		&& (params->local_count < params->width_field))
		putcharcount(' ', params);
}

static void	strminlenprecision(char *s, t_params *params)
{
	while (s[params->nb_chars_var])
		params->nb_chars_var++;
	if (params->flags_field & PRECISION
		&& params->nb_chars_var > params->precision_field)
		params->nb_chars_var = params->precision_field;
}

static void	strmaxlenwidth(t_params *params)
{
	if (params->nb_chars_var > params->width_field)
		params->width_field = params->nb_chars_var;
}

void	putstring(char *s, t_params *params)
{
	if (!s)
		s = "(null)";
	strminlenprecision(s, params);
	strmaxlenwidth(params);
	while (!(params->flags_field & MINUS)
		&& (params->nb_chars_var + params->local_count
			< params->width_field))
		putcharcount(' ', params);
	while (*s && !(params->flags_field & MINUS)
		&& (params->local_count < params->width_field))
		putcharcount(*s++, params);
	while (*s && (params->flags_field & MINUS)
		&& (params->local_count < params->nb_chars_var))
		putcharcount(*s++, params);
	while ((params->flags_field & MINUS)
		&& (params->local_count < params->width_field))
		putcharcount(' ', params);
}
