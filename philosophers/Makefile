NAME = philo

SRC = src/init.c \
	src/list.c \
	src/loop.c \
	src/parsing.c \
	src/philosophers.c \
	src/time.c \
	src/utils.c

OBJ = ${SRC:.c=.o}

CC = gcc ${CFLAGS}

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ} -lpthread

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re