/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:26:23 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:28:48 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*format_precision(char *itoa, t_parser *pars)
{
	char	*str;
	int		itoa_len;
	int		i;

	str = malloc(sizeof(char) * pars->precision);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < pars->precision)
	{
		str[i] = '0';
		i++;
	}
	itoa_len = ft_strlen(itoa);
	while (itoa_len)
	{
		str[i - 1] = itoa[itoa_len - 1];
		itoa_len--;
		i--;
	}
	return (str);
}

void	set_pcswidth(t_parser *pars, char *itoa)
{
	if (pars->precision > -1)
		pars->fill_w0 = 0;
	if (pars->precision < (int)ft_strlen(itoa))
		pars->precision = ft_strlen(itoa);
	if (pars->width < pars->precision + pars->isneg)
		pars->width = pars->precision + pars->isneg;
}

int		format_int(t_parser *pars, int nb)
{
	char *str;
	char *itoa;
	char *pcs_str;

	if (nb == 0 && pars->precision == 0)
	{
		pars->fill_w0 = 0;
		return (format_str(pars, ""));
	}
	itoa = ft_itoa(nb, "0123456789", pars);
	if (itoa == NULL)
		return (0);
	set_pcswidth(pars, itoa);
	str = malloc(sizeof(char) * (pars->width + 1));
	if (str == NULL)
		return (0);
	str = fill_sp0(str, pars);
	pcs_str = format_precision(itoa, pars);
	if (pcs_str == NULL)
		return (0);
	check_condition(pars, str, pcs_str);
	str[pars->width] = '\0';
	ft_wrstr(str, 1, pars->width);
	memfree(3, str, itoa, pcs_str);
	return (pars->width);
}

int		format_uint(t_parser *pars, unsigned int nb)
{
	char *str;
	char *itoa;
	char *pcs_str;

	if (nb == 0 && pars->precision == 0)
	{
		pars->fill_w0 = 0;
		return (format_str(pars, ""));
	}
	itoa = ft_uitoa(nb, "0123456789");
	if (itoa == NULL)
		return (0);
	set_pcswidth(pars, itoa);
	str = malloc(sizeof(char) * (pars->width + 1));
	if (str == NULL)
		return (0);
	str = fill_sp0(str, pars);
	pcs_str = format_precision(itoa, pars);
	if (pcs_str == NULL)
		return (0);
	check_condition_uint(pars, str, pcs_str);
	memfree(3, str, itoa, pcs_str);
	return (pars->width);
}

int		format_hex(t_parser *pars, unsigned int nb)
{
	char *str;
	char *itoa;
	char *pcs_str;

	if (nb == 0 && pars->precision == 0)
	{
		pars->fill_w0 = 0;
		return (format_str(pars, ""));
	}
	if (pars->type == HEX)
		itoa = ft_uitoa(nb, "0123456789abcdef");
	else
		itoa = ft_uitoa(nb, "0123456789ABCDEF");
	if (itoa == NULL)
		return (0);
	set_pcswidth(pars, itoa);
	str = malloc(sizeof(char) * (pars->width + 1));
	if (str == NULL)
		return (0);
	str = fill_sp0(str, pars);
	if ((pcs_str = format_precision(itoa, pars)) == NULL)
		return (0);
	check_condition_hex(pars, str, pcs_str);
	memfree(3, str, itoa, pcs_str);
	return (pars->width);
}
