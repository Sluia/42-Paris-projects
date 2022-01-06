/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:53:06 by bmayer            #+#    #+#             */
/*   Updated: 2021/01/25 16:47:06 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "stdio.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_l;
	char		c[11];
	int			sign;
	int			i;

	n_l = n;
	i = -1;
	sign = 0;
	while (i < 10)
		c[++i] = 0;
	if (n_l < 0)
	{
		sign = 1;
		n_l = -n_l;
	}
	if (n_l == 0)
		c[i--] = '0' + n_l % 10;
	while (n_l > 0)
	{
		c[i--] = '0' + n_l % 10;
		n_l = n_l / 10;
	}
	if (sign)
		c[i--] = '-';
	write(fd, c + (i + 1), 10 - i);
}
