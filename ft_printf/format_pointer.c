/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:16:07 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:16:40 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		format_pointer(t_parser *pars, unsigned long nb)
{
	char *str;
	char *itoa;
	char *itoa_0x;

	if (nb == 0 && pars->precision == 0)
	{
		pars->precision = 2;
		return (format_str(pars, "0x"));
	}
	itoa = ft_pitoa(nb, "0123456789abcdef");
	if (itoa == NULL)
		return (0);
	itoa_0x = malloc(sizeof(char) * (ft_strlen(itoa) + 3));
	if (itoa_0x == NULL)
		return (0);
	ft_strcpy(&itoa_0x[2], itoa, ft_strlen(itoa));
	set_0x(itoa_0x, itoa);
	if (pars->width < (int)ft_strlen(itoa_0x))
		pars->width = ft_strlen(itoa_0x);
	str = malloc(sizeof(char) * (pars->width + 1));
	if (str == NULL)
		return (0);
	format_pointer2(pars, str, itoa_0x);
	memfree(3, str, itoa, itoa_0x);
	return (pars->width);
}

void	format_pointer2(t_parser *pars, char *str, char *itoa_0x)
{
	str = fill_sp0(str, pars);
	if (pars->left_align)
		ft_strcpy(str, itoa_0x, pars->width);
	else
		ft_strcpy(&str[pars->width - ft_strlen(itoa_0x)], itoa_0x, pars->width);
	str[pars->width] = '\0';
	ft_wrstr(str, 1, pars->width);
}

void	set_0x(char *itoa_0x, char *itoa)
{
	itoa_0x[0] = '0';
	itoa_0x[1] = 'x';
	itoa_0x[ft_strlen(itoa) + 2] = '\0';
}
