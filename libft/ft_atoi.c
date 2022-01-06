/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:59:11 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 10:59:20 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
	|| *str == '\f' || *str == '\r' || *str == '\n')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (sign * result);
}
