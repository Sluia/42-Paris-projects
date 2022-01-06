NAME = pipex

SRC = src/close.c \
		src/errors.c \
		src/init.c \
		src/parsing.c \
		src/pipex.c \
		src/split.c \
		src/utils1.c \
		src/utils2.c \
		src/utils3.c

OBJ = ${SRC:.c=.o}

CC = gcc ${CFLAGS}

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re