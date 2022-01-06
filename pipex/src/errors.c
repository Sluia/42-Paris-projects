/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:15:12 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:15:22 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	call_error(char *error_msg, t_data *st)
{
	free_all(st);
	write_str_nl(error_msg);
	exit(EXIT_FAILURE);
}
