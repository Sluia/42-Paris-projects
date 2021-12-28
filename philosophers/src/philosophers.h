#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// how to compile with threads:
// => gcc <args> <program> -lpthread

typedef struct s_node
{
	pthread_t th;
	int id;
	int time_last_meal;
	int nb_meals;
	struct s_node *next;
} t_node;

typedef struct s_data
{
	t_node *philos;
	pthread_t checker;
	int time_ms;
	int nb_philos;
	int time_die;
	int time_eat;
	int time_sleep;
	int must_eat_nb;
} t_data;

void init_pars(t_data *info);

int parsing(t_data *info, int argc, char **argv);
int only_digit(char *str);
void set_pars_values(t_data *info, int nb, int i);
int valid_values(t_data *info);

long ft_atoi(const char *str);
int ft_isdigit(int c);
int ft_strlen(const char *str);
void *ft_calloc(int nb_elem, int size);
void *ft_memset(void *ptr, int c, int n);
int ft_strcmp(char *str1, char *str2);

#endif