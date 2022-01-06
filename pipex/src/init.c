/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:15:32 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:15:36 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_st(t_data *st)
{
	st->split = NULL;
	st->args_cmd1 = NULL;
	st->args_cmd2 = NULL;
	st->path_cmd1 = NULL;
	st->path_cmd2 = NULL;
	st->fd_pipe[0] = -1;
	st->fd_pipe[1] = -1;
	st->fd_file = -1;
}
