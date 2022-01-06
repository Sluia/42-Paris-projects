/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <qduarte@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:20:19 by qduarte           #+#    #+#             */
/*   Updated: 2020/12/03 11:36:42 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef enum	e_type
{
	INT,
	CHAR,
	STRING,
	POINTER,
	UNSIGNED_INT,
	HEX,
	HEX_CAPS,
	PERCENTAGE
}				t_type;

typedef struct	s_parser
{
	t_type	type;
	int		left_align;
	int		fill_w0;
	int		width;
	int		precision;
	int		isneg;
}				t_parser;

int				ft_printf(const char *format, ...) __attribute__
((format(printf,1,2)));
int				parse_spec(const char *cvers, va_list args);
int				format(t_parser *pars, va_list args);

int				format_char(t_parser *pars, int c);

int				format_str(t_parser *pars, char *arg_str);

char			*format_precision(char *itoa, t_parser *pars);
void			set_pcswidth(t_parser *pars, char *itoa);
int				format_int(t_parser *pars, int nb);
int				format_uint(t_parser *pars, unsigned int nb);
int				format_hex(t_parser *pars, unsigned int nb);

int				format_pointer(t_parser *pars, unsigned long nb);
void			format_pointer2(t_parser *pars, char *str, char *itoa_0x);
void			set_0x(char *itoa_0x, char *itoa);

void			init_parser(t_parser *pars);
t_type			set_type(char c);
void			set_flags(t_parser *pars, char c);
void			set_width(t_parser *pars, char c, va_list args);
void			set_precision(t_parser *pars, char c, va_list args);

int				ft_isdigit(int c);
void			ft_wrchar(char c, int fd);
void			ft_wrstr(char *str, int fd, int len);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src, size_t n);
char			*fill_sp0(char *str, t_parser *pars);
void			memfree(int nb, ...);
int				index_spec(const char *str);
char			*rev_arr(char *str, int nb_len);

void			check_condition(t_parser *pars, char *str, char *pcs_str);
void			check_cdtleft(t_parser *pars, char *str, char *pcs_str);
void			check_cdtright(t_parser *pars, char *str, char *pcs_str);
void			check_condition_uint(t_parser *pars, char *str, char *pcs_str);
void			check_condition_hex(t_parser *pars, char *str, char *pcs_str);

int				get_nblen(unsigned long ulnb, int base_size);
char			*fill_itoa(char *str, char *base, unsigned long ulnb);
char			*ft_itoa(int nb, char *base, t_parser *pars);
char			*ft_uitoa(unsigned int unb, char *base);
char			*ft_pitoa(unsigned long ulnb, char *base);

#endif
