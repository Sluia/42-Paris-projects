/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte </var/mail/qduarte>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:18:00 by qduarte           #+#    #+#             */
/*   Updated: 2021/08/31 13:29:50 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**split;
	char	**args_cmd1;
	char	**args_cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
	int		fd_pipe[2];
	int		fd_file;
	pid_t	pid1;
	pid_t	pid2;
}	t_data;

void	free_all(t_data *st);

void	call_error(char *error_msg, t_data *st);

void	init_st(t_data *st);

void	get_split_path(t_data *st, char *envp[], size_t i, size_t j);
void	get_all_args(t_data *st, char *args1, char *args2);
char	*get_path(char **split, char **args);

char	**ft_split(char const *str, char delim);
size_t	ft_split_wc(char const *str, char delim);
char	**ft_split_arr(char **split, char const *str, char delim);
size_t	ft_split_cc(char const *str, char delim);

void	close_fd(int *fd);
void	*ft_calloc(size_t nb_items, size_t size);
void	ft_free(char **to_free);
void	ft_free_2d(char ***to_free);
void	*ft_memset(void *ptr, int c, size_t n);

char	*ft_strcat(char *dest, const char *src, size_t n);
int		ft_strcmp(const char *str1, const char *str2, size_t n);
char	*ft_strcpy(char *dest, char const *src, size_t n);
size_t	ft_strcpy_i(char *dest, char const *src, size_t n);
char	*ft_strdup(char const *src, size_t n);

char	*ft_strjoin(char *str1, char const *str2, int to_free);
size_t	ft_strlen(const char *str);
void	write_str_nl(char *str);

#endif
