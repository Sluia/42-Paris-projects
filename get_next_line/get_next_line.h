/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 09:15:47 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/22 09:16:18 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

void	clear_buf(char *buffer, int index);
int		chk_buf_read(char *buffer, int *p_buf_len, char **line);
int		to_return(char **line, int buf_len);
int		get_next_line(int fd, char **line);

int		ft_strlen(char *str);
int		cpy_buf(char *buffer, int index, int len);
int		nl_index(char *buffer, int len);
char	*ft_strdup(char *src, int len);
char	*ft_strjoin(char *line, char *str2, int len);

#endif
