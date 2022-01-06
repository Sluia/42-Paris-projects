/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:15:58 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:30:08 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_first(t_data *st, char *argv[], char *envp[])
{
	st->pid1 = fork();
	if (st->pid1 == -1)
		call_error("Error: failed to execute fork", st);
	if (st->pid1 == 0)
	{
		st->fd_file = open(argv[1], O_RDONLY);
		if (st->fd_file == -1)
			call_error("Error: failed to open the file", st);
		st->path_cmd1 = get_path(st->split, st->args_cmd1);
		if (st->path_cmd1 == NULL)
			call_error("Error: command not found", st);
		if (dup2(st->fd_file, STDIN_FILENO) == -1)
			call_error("Error: unable to duplicate FD", st);
		close(st->fd_file);
		if (dup2(st->fd_pipe[1], STDOUT_FILENO) == -1)
			call_error("Error: unable to duplicate FD", st);
		close(st->fd_pipe[0]);
		close(st->fd_pipe[1]);
		if (execve(st->path_cmd1, st->args_cmd1, envp) == -1)
			call_error("Error: failed to execute execve", st);
	}
}

void	exec_second(t_data *st, char *argv[], char *envp[])
{
	st->pid2 = fork();
	if (st->pid2 == -1)
		call_error("Error: failed to execute fork", st);
	if (st->pid2 == 0)
	{
		st->fd_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (st->fd_file == -1)
			call_error("Error: failed to open the file", st);
		st->path_cmd2 = get_path(st->split, st->args_cmd2);
		if (st->path_cmd2 == NULL)
			call_error("Error: command not found", st);
		if (dup2(st->fd_file, STDOUT_FILENO) == -1)
			call_error("Error: unable to duplicate FD", st);
		close(st->fd_file);
		if (dup2(st->fd_pipe[0], STDIN_FILENO) == -1)
			call_error("Error: unable to duplicate FD", st);
		close(st->fd_pipe[0]);
		close(st->fd_pipe[1]);
		if (execve(st->path_cmd2, st->args_cmd2, envp) == -1)
			call_error("Error: failed to execute execve", st);
	}
}

void	pipex(t_data *st, char *argv[], char *envp[])
{
	if (pipe(st->fd_pipe))
		call_error("Error: failed to create the pipe", st);
	exec_first(st, argv, envp);
	exec_second(st, argv, envp);
	close_fd(&st->fd_pipe[0]);
	close_fd(&st->fd_pipe[1]);
	if (waitpid(st->pid1, NULL, 0) == -1)
		call_error("Error: failed to execute waitpid", st);
	if (waitpid(st->pid2, NULL, 0) == -1)
		call_error("Error: failed to execute waitpid", st);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	st;

	init_st(&st);
	if (argc == 5)
	{
		get_split_path(&st, envp, 0, 0);
		get_all_args(&st, argv[2], argv[3]);
		pipex(&st, argv, envp);
		free_all(&st);
	}
	else
		call_error("Error: invalid number of arguments", &st);
	return (0);
}
