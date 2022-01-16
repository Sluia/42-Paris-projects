NAME = philo

SRC = src/deaths.c \
	src/free.c \
	src/init.c \
	src/list.c \
	src/loop.c \
	src/mutex.c \
	src/output.c \
	src/parsing.c \
	src/philosophers.c \
	src/time.c \
	src/utils_1.c \
	src/utils_2.c \
	src/utils_3.c

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