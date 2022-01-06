NAME		= minishell

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -I. -I/Users/bmayer/Desktop/homebrew/opt/readline/include

RM			= rm -rf

UTILS_DIR	= ./utils/

UTILS_INC	= -I$(UTILS_DIR)

UTILS_NAME	= libutils.a

LIBS		= -L. -lutils -lreadline -L/Users/bmayer/Desktop/homebrew/opt/readline/lib

SRCS		= $(addprefix src/, \
				builtin_cd.c \
				builtin_echo.c \
				builtin_env.c \
				builtin_exit.c \
				builtin_export.c \
				builtin_pwd.c \
				builtin_unset.c \
				cmd.c \
				cmd2.c \
				error.c \
				exec.c \
				exec2.c \
				exec3.c \
				expand_variables.c \
				free.c \
				free2.c \
				handling_redirection.c \
				heredoc.c \
				init.c \
				lexing.c \
				minishell.c \
				parsing.c \
				parsing2.c \
				parsing3.c \
				signal.c \
				utils.c \
				utils2.c)

OBJS		=$(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) $(UTILS_INC) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(UTILS_NAME) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C $(UTILS_DIR)
			$(RM) $(UTILS_NAME)
			$(RM) $(NAME)

re:			fclean all

$(UTILS_NAME):
			make -C $(UTILS_DIR)
			mv $(UTILS_DIR)$(UTILS_NAME) .
			make clean -C $(UTILS_DIR)

test:		src/expand_variables.c
			$(CC) $(CFLAGS) $(UTILS_INC) $(LIBS) src/expand_variables.c -o test
			./test

