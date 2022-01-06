NAME	= libutils.a

CC		= clang

CFLAGS 	= -Wall -Wextra -Werror -I.

RM		= rm -rf

LIB		= ar rcs

LIBFT	=$(addprefix lib/, \
			ft_arrlen.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_free_1d.c \
			ft_free_2d.c \
			ft_free_3d.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isline.c \
			ft_isnum.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstmove.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strchr_int.c \
			ft_strcmp_min.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strlcat.c \
			ft_strlcat_ptr.c \
			ft_strlcpy.c \
			ft_strlcpy_int.c \
			ft_strlen.c \
			ft_strlen_eol.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strndup.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_swap.c \
			ft_tolower.c \
			ft_toupper.c \
			write_str_nl.c)

PRINTF = $(addprefix ptf/, \
			ft_parser.c \
			ft_printf.c \
			ft_putinteger.c \
			ft_putpct.c \
			ft_putpointer.c \
			ft_putstring.c)

SRCS	=$(LIBFT) $(PRINTF) $(GNL)

OBJS	=$(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
