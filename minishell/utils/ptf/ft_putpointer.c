/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:20:27 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 17:23:31 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	hexrec(unsigned long int nb, t_params *params)
{
	int	mod;

	if (nb >= 16)
		hexrec(nb / 16, params);
	mod = (int)(nb % 16);
	if (mod <= 9)
		putcharcount('0' + mod, params);
	if (mod > 9)
	{
		if (params->length_field & HEXA_MAJ)
			putcharcount('A' + mod - 10, params);
		if (params->length_field & HEXA_MIN)
			putcharcount('a' + mod - 10, params);
	}
}

static void	ptrnbchar(unsigned long int ptr, t_params *params)
{
	if (!(ptr) && params->flags_field & PRECISION)
		params->nb_chars_var = 2;
	else
	{
		intlen(ptr, params);
		params->nb_chars_var = params->nb_chars_var + 2;
	}
}

void	putpointer(unsigned long int ptr, t_params *params)
{
	params->length_field |= HEXA_MIN;
	ptrnbchar(ptr, params);
	while (!(params->flags_field & MINUS)
		&& (params->local_count < params->width_field - params->nb_chars_var))
		putcharcount(' ', params);
	putcharcount('0', params);
	putcharcount('x', params);
	if (ptr)
		hexrec(ptr, params);
	else if (!(params->flags_field & PRECISION))
		putcharcount('0', params);
	while ((params->flags_field & MINUS)
		&& (params->local_count < params->width_field))
		putcharcount(' ', params);
}
