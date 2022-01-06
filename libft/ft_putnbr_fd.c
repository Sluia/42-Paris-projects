/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:17:56 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:17:57 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long l_nb;

	l_nb = nb;
	if (l_nb < 0)
	{
		ft_putchar_fd('-', fd);
		l_nb *= -1;
	}
	if (l_nb > 9)
	{
		ft_putnbr_fd(l_nb / 10, fd);
		ft_putchar_fd((l_nb % 10) + 48, fd);
	}
	else
	{
		ft_putchar_fd(l_nb + 48, fd);
	}
}
