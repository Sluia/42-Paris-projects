/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduarte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:55:18 by qduarte           #+#    #+#             */
/*   Updated: 2021/09/16 10:31:32 by qduarte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nb;
	int				sorted_nb;
	struct s_node	*next;
}	t_node;

typedef struct s_main
{
	t_node	*a;
	t_node	*b;
	char	***split_args;
	char	*args_space;
	int		nb_nb;
}	t_main;

void		launch_algo(t_main *data);
void		algo_2(t_main *data);
void		algo_3(t_main *data);
void		algo_small(t_main *data);
void		algo_big(t_main *data, int chunk_size);

int			get_highest_nb_list(t_node *top);
int			get_lowest_nb_list(t_node *top);
int			get_higher_nb_list(t_node *top, int sorted_nb);
void		push_back_to_a(t_main *data);
void		rotate_a(t_main *data, int nb_list, int node_position);

void		push_chunk_to_b(t_main *data, int chunk, int chunk_size);
int			total_nb_chunk(t_node *top, int chunk, int chunk_size);
int			chunk_in_list_first(t_node *top, int chunk, int chunk_size);
int			chunk_in_list_last(t_node *top, int chunk, int chunk_size);

void		free_list(t_node *top);
void		ft_free_1d(char **to_free);
void		ft_free_2d(char ***to_free);
void		ft_free_3d(char ****to_free);

void		sa(t_node **top);
void		sb(t_node **top);
void		ss(t_node **top_a, t_node **top_b);

void		pa(t_node **top_a, t_node **top_b);
void		pb(t_node **top_a, t_node **top_b);
void		ra(t_node **top_a);
void		rb(t_node **top_b);
void		rr(t_node **top_a, t_node **top_b);

void		rra(t_node **top_a);
void		rrb(t_node **top_b);
void		rrr(t_node **top_a, t_node **top_b);

t_node		*new_node(int nb);
void		add_node_front(t_node **top, t_node *new);
void		add_node_back(t_node **top, t_node *new);
int			get_list_length(t_node *top);

t_node		*get_node_wpos(t_node *top, int pos);
t_node		*get_node_wnb(t_node *top, int nb);
int			get_pos_node(t_node *top, int sorted_nb);

void		parse_list(t_main *data, int argc, char *argv[]);
void		build_list(t_main *data);
void		build_list_2(t_main *data, int i, int j);
int			is_arg_valid(char *arg);
int			check_duplicates(t_node *a);

void		init_st(t_main *data);
void		end_program(t_main *data, int error);

void		add_sorted_nb(t_main *data);
void		sort_array(int *array_nb, int nb_nb);
int			is_list_sorted(t_node *top);

char		**ft_split(char const *str, char delim);
size_t		ft_split_wc(char const *str, char delim);
char		**ft_split_arr(char **split, char const *str, char delim);
size_t		ft_split_cc(char const *str, char delim);

long long	ft_atoi(const char *str);
char		*ft_strdup(char const *src, size_t n);
char		*ft_strjoin(char *str1, char const *str2);
void		write_str_nl(char *str, int fd);

void		*ft_calloc(size_t nb_items, size_t size);
void		*ft_memset(void *ptr, int c, size_t n);
int			ft_isdigit(int c);
int			ft_is_sign_space(int c);

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dest, char const *src, size_t n);
size_t		ft_strcpy_i(char *dest, char const *src, size_t n);
char		*ft_strcat(char *dest, const char *src, size_t n);

#endif
