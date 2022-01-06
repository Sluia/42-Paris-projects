/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:05:03 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 11:05:56 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_cst_nb_len(long nb)
{
	size_t len;

	len = 1;
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa_cst_fill_array(char *nb_str, long l_nb,
		int is_neg, size_t nb_len)
{
	if (is_neg)
	{
		while (nb_len > 1)
		{
			nb_str[nb_len - 1] = (l_nb % 10) + 48;
			l_nb /= 10;
			nb_len--;
		}
		nb_str[nb_len - 1] = '-';
	}
	else
	{
		while (nb_len > 0)
		{
			nb_str[nb_len - 1] = (l_nb % 10) + 48;
			l_nb /= 10;
			nb_len--;
		}
	}
	return (nb_str);
}

char	*ft_itoa(int nb)
{
	char	*nb_str;
	long	l_nb;
	int		is_neg;
	size_t	nb_len;

	l_nb = nb;
	nb_len = 0;
	is_neg = 0;
	if (l_nb < 0)
	{
		l_nb *= -1;
		is_neg = 1;
		nb_len += 1;
	}
	nb_len += ft_itoa_cst_nb_len(l_nb);
	nb_str = ft_calloc(nb_len + 1, sizeof(char));
	if (nb_str == NULL)
	{
		return (NULL);
	}
	nb_str = ft_itoa_cst_fill_array(nb_str, l_nb, is_neg, nb_len);
	nb_str[nb_len] = '\0';
	return (nb_str);
}
