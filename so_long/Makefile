NAME = so_long

SRC = src/close.c \
	src/draw.c \
	src/errors.c \
	src/game.c \
	src/get_next_line_utils.c \
	src/get_next_line.c \
	src/init.c \
	src/move.c \
	src/parsing.c \
	src/parsing2.c \
	src/so_long.c \
	src/utils.c \
	src/utils2.c

MLXDIR = mlx_linux

OBJ = ${SRC:.c=.o}

CC = gcc ${CFLAGS}

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -Lmlx_linux/ -lmlx -lXext -lX11 -lm

RM = rm -rf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	make -C ${MLXDIR}
	${CC} -o ${NAME} ${OBJ} ${MLXFLAGS}

all: ${NAME}

clean:
	make -C ${MLXDIR} clean
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re