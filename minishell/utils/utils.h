/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:23 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:53:32 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4095
# endif

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef enum e_flags {
	MINUS = 1,
	PLUS = 2,
	SPACES = 4,
	ZERO = 8,
	APOSTROPHE = 16,
	HASH = 32,
	PRECISION = 64,
	WIDTH = 128
}	t_flags;

typedef enum e_length {
	CHAR = 1,
	SHORT = 2,
	LONG = 4,
	LONG_LONG = 8,
	HEXA_MIN = 16,
	HEXA_MAJ = 32
}	t_length;

typedef struct s_params
{
	unsigned char	flags_field;
	int				width_field;
	int				precision_field;
	unsigned int	length_field;
	int				nb_chars_var;
	int				sign;
	int				local_count;
	int				global_count;
}	t_params;

int					ft_arrlen(char **arr);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, int n);
void				*ft_calloc(int count, int size);
void				ft_free_1d(char **to_free);
void				ft_free_2d(char ***to_free);
void				ft_free_3d(char ****to_free);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isline(const char *s);
int					ft_isnum(char *str);
int					ft_isprint(int c);
int					ft_isspace(int c);
void				*ft_memccpy(void *dst, const void *src, int c, int n);
void				*ft_memchr(const void *s, int c, int n);
int					ft_memcmp(const void *s1, const void *s2, int n);
void				*ft_memcpy(void *dst, const void *src, int n);
void				*ft_memmove(void *dst, const void *src, int len);
void				*ft_memset(void *b, int c, int len);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_int(char *s, char c);
int					ft_strcmp_min(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strdup(const char *src);
int					ft_strlcat(char *dst, const char *src, int dstsize);
char				*ft_strlcat_ptr(char *dest, const char *src, int n);
char				*ft_strlcpy(char *dst, const char *src, int n);
int					ft_strlcpy_int(char *dest, char const *src, int n);
int					ft_strlen_eol(const char *str);
int					ft_strlen(const char *s);
int					ft_strncmp(char *str1, char *str2, int n);
char				*ft_strndup(const char *src, unsigned int len);
char				*ft_strnstr(const char *haystack, const char *needle,
						int len);
char				*ft_strrchr(const char *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *str1, char const *str2, int to_free);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, int len);
void				ft_swap(int *a, int *b);
void				ft_lstadd_back(t_list **alst, t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *lst);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstmove(t_list *lst, int index);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				write_str_nl(char *str);

int					ft_printf(const char *format, ...);
const char			*flags(const char *format, t_params *params);
const char			*width(const char *format, t_params *params, va_list ap);
const char			*precision(const char *format, t_params *params,
						va_list ap);
const char			*length(const char *format, t_params *params);
const char			*conversion(const char *format, t_params *params,
						va_list ap);
void				putcharcount(char c, t_params *params);
void				putcharformatted(unsigned char c, t_params *params);
void				putint(long int nb, t_params *params);
void				intlen(long long int nb, t_params *params);
void				putstring(char *s, t_params *params);
void				putpointer(unsigned long int ptr, t_params *params);
void				hexrec(unsigned long int nb, t_params *params);
void				putpctformatted(t_params *params);

#endif
