NAME = libftprintf.a

SRC = format_char.c format_int.c format_pointer.c format_str.c \
	ft_itoa.c ft_printf.c setters.c utils.c utils2.c utils_int.c

OBJ = ${SRC:.c=.o}

CC = gcc ${CFLAGS}

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

.c.o:
	${CC} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
