/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:15:10 by bmayer            #+#    #+#             */
/*   Updated: 2021/11/29 20:48:25 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "utils.h"

# define C_YELLOW "\x1B[33m"
# define C_RESET "\x1B[0m"

typedef enum s_type
{
	ASCII,
	DQUOTE,
	SQUOTE,
	REDIR,
	WSPACE,
	PIPE,
	WORD
}	t_type;

typedef struct s_lex
{
	char	*str;
	t_type	type;
}	t_lex;

typedef struct s_redir
{
	int		fd;
	int		index;
	char	*filename;
}	t_redir;

typedef struct s_cmd
{
	pid_t	pid;
	int		nb_redir;
	t_redir	*list_redir;
	int		pipe_in;
	int		pipe_out;
	char	*path_cmd;
	char	**args;
}	t_cmd;

typedef struct s_data
{
	char	*input;
	char	**split_path;
	char	**envp;
	int		**fd_pipes;
	t_list	*tokens;
	t_list	*words;
	int		nb_cmd;
	t_cmd	*list_cmd;
	int		err;
	int		clone_stdout;
}	t_data;

t_data	g_st;

/* Lexing */

int		lexer(void);
void	*new_lex(char *str, int nb_char, t_type type);
void	*add_lex(char *str, int nb_char, t_type type);
int		push_lex(int i, t_type type);

/* Parsing */

int		parser(void);
int		parse_type(t_list *tmp, t_type curr, t_type prev);
int		parse_ascii(t_list *token, t_type prev);
int		parse_quote(t_list *token, char quote, t_type prev);
int		parse_pipe(t_list *token);
int		parse_redirection(t_list *token);
void	*add_word(char *str, t_type type);
int		push_word(char *str, t_type type, t_type prev);
int		join_word(char *str);
int		is_tilde(t_list	*tmp);
int		parse_tilde(void);

/* Exec */

int		init_pipes(void);
int		init_cmd(void);
int		get_split_path(void);
int		join_path(void);
int		cmd_pipe(int *n_cmd);
int		cmd_redir(t_list *tmp, int n_cmd, int index_redir);
int		cmd_word(t_list *tmp, int n_cmd);
int		cmds_valid(void);
int		prepare_st_cmd(void);
int		exec_cmd(void);
int		exec_builtin(char **argv);
int		is_builtin(char **argv);
char	*get_cmd_path(char **split, char *arg);
int		handling_redirection(int i);
int		handling_redirection_1(int i, int j);
int		handling_redirection_2_4(int i, int j);
int		heredoc(int i, int j);
int		handling_pipes(int i);
int		close_pipe_fd(void);
int		wait_end_exec(void);
int		exec_child(int i);

/* Helpers */

char	get_char(t_list *token, int i);
t_type	get_type(t_list *token);
char	*get_str(t_list *token);
char	*ft_strndup_lst(t_list *token, int nb_char);
int		ft_invascii(char c);
int		get_redir(t_list *word);
int		get_redir2(t_list *word);
int		get_nbredir(t_list	*tmp);
int		get_nb_cmd(void);
int		get_nb_words(void);
char	**add_arg(char	*arg, char **args);

/* Signals */

void	init_st(void);
void	init_signal(void);
void	signal_handler(int sig);

/* Free */

void	free_all(void);
void	free_lex(void *lex);
void	free_tokens(void);
void	free_words(void);
void	free_cmd(void);
void	free_pipes(void);

void	clean_exit(int sig);
int		err(int err_num);
int		malloc_envp(char **envp);

/* Builtins */

int		ft_cd(char **argv);
int		ft_echo(char **argv);
int		ft_env(char **argv);
int		ft_export(char **argv);
int		ft_pwd(char **argv);
int		ft_unset(char **argv);
int		ft_exit(char **argv);

int		ft_export_display(void);
char	*ft_getenv(char *str);
int		ft_putenv(char *var);
int		ft_setenv(char *str);

char	*exp_vars(char *str);

#endif
