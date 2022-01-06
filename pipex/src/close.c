/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:14:53 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:14:59 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *st)
{
	ft_free_2d(&st->split);
	ft_free_2d(&st->args_cmd1);
	ft_free_2d(&st->args_cmd2);
	ft_free(&st->path_cmd1);
	ft_free(&st->path_cmd2);
	close_fd(&st->fd_pipe[0]);
	close_fd(&st->fd_pipe[1]);
	close_fd(&st->fd_file);
}
