/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinteger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:12:38 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 17:23:11 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	intlen(long long int nb, t_params *params)
{
	if (!nb)
		params->nb_chars_var = 1;
	if (nb < 0)
	{
		nb = -nb;
		params->sign = 1;
	}
	while (nb >= 1)
	{
		if (params->length_field & HEXA_MIN || params->length_field & HEXA_MAJ)
			nb = nb / 16;
		else
			nb = nb / 10;
		params->nb_chars_var++;
	}
	if (params->nb_chars_var > params->precision_field)
		params->precision_field = params->nb_chars_var;
}

static void	intmaxlenwidth(t_params *params)
{
	if (params->precision_field + params->sign > params->width_field)
		params->width_field = params->precision_field + params->sign;
}

static void	numberrec(long int nb, t_params *params)
{
	if (params->length_field & HEXA_MIN || params->length_field & HEXA_MAJ)
	{
		hexrec(nb, params);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		numberrec(nb / 10, params);
	putcharcount('0' + nb % 10, params);
}

static void	putint_alignleft(long int nb, t_params *params)
{
	if ((params->flags_field & ZERO) && !(params->flags_field & PRECISION))
		if (params->sign)
			putcharcount('-', params);
	while (params->local_count
		< params->width_field - params->precision_field - params->sign)
		if ((params->flags_field & ZERO) && !(params->flags_field & PRECISION))
			putcharcount('0', params);
	else
		putcharcount(' ', params);
	if (!(params->flags_field & ZERO) || ((params->flags_field & ZERO)
			&& (params->flags_field & PRECISION)))
		if (params->sign)
			putcharcount('-', params);
	while (params->local_count < params->width_field - params->nb_chars_var)
		putcharcount('0', params);
	numberrec(nb, params);
}

void	putint(long int nb, t_params *params)
{
	if ((nb == 0) && (params->flags_field & PRECISION)
		&& !(params->precision_field))
	{
		while (params->local_count < params->width_field)
			putcharcount(' ', params);
		return ;
	}
	intlen(nb, params);
	intmaxlenwidth(params);
	if (!(params->flags_field & MINUS))
		putint_alignleft(nb, params);
	if ((params->flags_field & MINUS))
	{
		if (params->sign)
			putcharcount('-', params);
		while (params->local_count
			< params->precision_field - params->nb_chars_var + params->sign)
			putcharcount('0', params);
		numberrec(nb, params);
		while (params->local_count < params->width_field)
			putcharcount(' ', params);
	}
}
