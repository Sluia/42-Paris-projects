/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:04:09 by bmayer            #+#    #+#             */
/*   Updated: 2021/04/29 16:41:18 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	putpctformatted(t_params *params)
{
	while (!(params->flags_field & MINUS)
		&& (params->local_count < params->width_field - 1))
	{
		if ((params->flags_field & ZERO))
			putcharcount('0', params);
		else
			putcharcount(' ', params);
	}
	putcharcount('%', params);
	while ((params->flags_field & MINUS)
		&& (params->local_count < params->width_field))
		putcharcount(' ', params);
}
