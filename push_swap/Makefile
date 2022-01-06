NAME = push_swap

SRC = src/algorithm1.c \
	src/algorithm2.c \
	src/chunk.c \
	src/free.c \
	src/instructions1.c \
	src/instructions2.c \
	src/instructions3.c \
	src/list1.c \
	src/list2.c \
	src/parsing.c \
	src/push_swap.c \
	src/sort.c \
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