/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:47:13 by qduarte           #+#    #+#             */
/*   Updated: 2020/11/19 12:05:03 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *ptr, size_t n);
void			*ft_calloc(size_t nb_elem, size_t size);
void			*ft_memchr(const void *ptr, int c, size_t n);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *ptr, int c, size_t n);

int				ft_atoi(const char *str);
char			*ft_itoa(int nb);
char			**ft_split(char const *str, char delim);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(char *src);
char			*ft_strjoin(char const *str1, char const *str2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int				ft_strncmp(const char *str1, const char *str2, size_t n);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *str, char const *set);
char			*ft_substr(char const *str, unsigned int start, size_t len);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char *str, int fd);

void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

#endif
